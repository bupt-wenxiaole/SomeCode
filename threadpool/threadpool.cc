#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "threadpool.h"

#define DEFAULT_TIME 10 // ervery 10s check the task_queue and thread_status
#define MIN_WAIT_TASK_NUM 10 // if queue_size > MIN_WAIT_TASK_NUM, we need add thread
#define DEFAULT_THREAD_VARY 10 //# of thread num vary


typedef struct
{
	void *(*function)(void *);       //任务队列数据结构 封装了线程需要去执行的函数指针和传入参数                  
	void *arg;
} threadpool_task_t;


struct threadpool_t
{
	pthread_mutex_t lock;// mutex for the taskpool
	pthread_mutex_t thread_counter;//mutex for count the busy thread
	pthread_cond_t queue_not_full;      //队列不满
	pthread_cond_t queue_not_empty;      //队列不空
	pthread_t *threads;
	pthread_t adjust_tid;
	threadpool_task_t *task_queue;
	int min_thr_num;
	int max_thr_num;
	int live_thr_num;
	int busy_thr_num;
	int wait_exit_thr_num;
	int queue_front;
	int queue_rear;
	int queue_size;
	int queue_max_size;
	bool shutdown;
};

/**
 * @function void *threadpool_thread(void *threadpool)
 * @desc the worker thread
 * @param threadpool the pool which own the thread
 */
void *threadpool_thread(void *threadpool);
/**
 * @function void *adjust_thread(void *threadpool);
 * @desc manager thread
 * @param threadpool the threadpool
 */
void *adjust_thread(void *threadpool);
/**
 * check a thread is alive
 */
bool is_thread_alive(pthread_t tid);

int threadpool_free(threadpool_t *pool);

threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size)
{
	threadpool_t *pool = NULL;
    do{
	    if((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL)
	    {
		    printf("malloc threadpool fail");
		    break;
	    }

	    pool->min_thr_num = min_thr_num;
	    pool->max_thr_num = max_thr_num;
	    pool->busy_thr_num = 0;
	    pool->live_thr_num = min_thr_num;
	    pool->queue_size = 0;
	    pool->queue_max_size = queue_max_size;
	    pool->queue_front = 0;
	    pool->queue_rear = 0;
	    pool->shutdown = false;

	    pool->threads = (pthread_t *)malloc(sizeof(pthread_t)*max_thr_num);
	    if (pool->threads == NULL)
	    {
	    	printf("malloc threads fail");
	    	break;
	    }
	    memset(pool->threads, 0, sizeof(pool->threads));

	    pool->task_queue = (threadpool_task_t *)malloc(sizeof(threadpool_task_t)*queue_max_size);
	    if (pool->task_queue == NULL)
	    {
	    	printf("malloc task_queue fail");
	    	break;
	    }

	    if (pthread_mutex_init(&(pool->lock), NULL) != 0
	    	|| pthread_mutex_init(&(pool->thread_counter), NULL) != 0
	    	|| pthread_cond_init(&(pool->queue_not_empty), NULL) != 0
	    	|| pthread_cond_init(&(pool->queue_not_full), NULL) != 0)
	    {
	    	printf("init the lock or cond fail");
	    	break;
	    }

	    /**
	     * start work thread  min_thr_num
	     */
	    for (int i = 0; i < min_thr_num; i++)
	    {
	    	pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void *)pool);
	    	printf("start thread 0x%x...\n", pool->threads[i]);
	    }
	    pthread_create(&(pool->adjust_tid), NULL, adjust_thread, (void *)pool);
	    return pool;

    }while(0);

    threadpool_free(pool);
	return NULL;
}

int threadpool_add(threadpool_t *pool, void*(*function)(void *arg), void *arg)
{
	assert(pool != NULL);
	assert(function != NULL);
	assert(arg != NULL);

	pthread_mutex_lock(&(pool->lock));

	while ((pool->queue_size == pool->queue_max_size) && (!pool->shutdown))
	{
		//queue full  wait
		pthread_cond_wait(&(pool->queue_not_full), &(pool->lock)); 
	}
	if (pool->shutdown)
	{
		pthread_mutex_unlock(&(pool->lock));
	}

	//add a task to queue
	if (pool->task_queue[pool->queue_rear].arg != NULL)  //队列的尾指针指向队列最后单元的下一个位置
	{
		free(pool->task_queue[pool->queue_rear].arg);
		pool->task_queue[pool->queue_rear].arg = NULL;
	}
	pool->task_queue[pool->queue_rear].function = function;
	pool->task_queue[pool->queue_rear].arg = arg;
	pool->queue_rear = (pool->queue_rear + 1)%pool->queue_max_size;
	pool->queue_size++;

	//queue not empty
	pthread_cond_signal(&(pool->queue_not_empty));
	pthread_mutex_unlock(&(pool->lock));

	return 0;
}

void *threadpool_thread(void *threadpool)
{
	threadpool_t *pool = (threadpool_t *)threadpool;
	threadpool_task_t task;
	while(true)
	{
		/* Lock must be taken to wait on conditional variable */
		pthread_mutex_lock(&(pool->lock));

		while ((pool->queue_size == 0) && (!pool->shutdown))
		{
			printf("thread 0x%x is waiting\n", pthread_self());
			pthread_cond_wait(&(pool->queue_not_empty), &(pool->lock));
			if (pool->wait_exit_thr_num > 0)
			{
				pool->wait_exit_thr_num--;   
				if (pool->live_thr_num > pool->min_thr_num)
				{
					printf("thread 0x%x is exiting\n", pthread_self());
				    pool->live_thr_num--;
				    pthread_mutex_unlock(&(pool->lock));
				    pthread_exit(NULL);
				}
			}
		}

		if (pool->shutdown)
		{
			pthread_mutex_unlock(&(pool->lock));
			printf("thread 0x%x is exiting\n", pthread_self());
			pthread_exit(NULL);
		}
		//get a task from queue
		task.function = pool->task_queue[pool->queue_front].function;
		task.arg = pool->task_queue[pool->queue_front].arg;
		pool->queue_front = (pool->queue_front + 1)%pool->queue_max_size;
		pool->queue_size--;

		//now queue must be not full
		pthread_cond_broadcast(&(pool->queue_not_full));

		pthread_mutex_unlock(&(pool->lock));

		// Get to work
		printf("thread 0x%x start working\n", pthread_self());
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num++;
		pthread_mutex_unlock(&(pool->thread_counter));
		(*(task.function))(task.arg);
		// task run over
		printf("thread 0x%x end working\n", pthread_self());
		pthread_mutex_lock(&(pool->thread_counter));
		pool->busy_thr_num--;
		pthread_mutex_unlock(&(pool->thread_counter));
	}

	pthread_exit(NULL);
	return (NULL);
}


void *adjust_thread(void *threadpool)
{
	threadpool_t *pool = (threadpool_t *)threadpool;
	while (!pool->shutdown)   //每隔DEFAULT_TIME调整一次线程池的大小
	{
		sleep(DEFAULT_TIME);
		pthread_mutex_lock(&(pool->lock));
		int queue_size = pool->queue_size;
		int live_thr_num = pool->live_thr_num;
		pthread_mutex_unlock(&(pool->lock));

		pthread_mutex_lock(&(pool->thread_counter));
		int busy_thr_num = pool->busy_thr_num;
		pthread_mutex_unlock(&(pool->thread_counter));

		if (queue_size >= MIN_WAIT_TASK_NUM
				&& live_thr_num < pool->max_thr_num)
		{
			//need add thread
			pthread_mutex_lock(&(pool->lock));
			int add = 0;
			for (int i = 0; i < pool->max_thr_num && add < DEFAULT_THREAD_VARY
			&& pool->live_thr_num < pool->max_thr_num; i++)
			{
				if (pool->threads[i] == 0 || !is_thread_alive(pool->threads[i]))
				{
					pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void *)pool);
					add++;
					pool->live_thr_num++;
				}
			}
			pthread_mutex_unlock(&(pool->lock));
		}

		if ((busy_thr_num * 2) < live_thr_num
				&& live_thr_num > pool->min_thr_num)
		{
			//need del thread
			pthread_mutex_lock(&(pool->lock));
			pool->wait_exit_thr_num = DEFAULT_THREAD_VARY;
			pthread_mutex_unlock(&(pool->lock));
			//wake up thread to exit
			for (int i = 0; i < DEFAULT_THREAD_VARY; i++)
			{
				pthread_cond_signal(&(pool->queue_not_empty));
			}
		}
	}
}

int threadpool_destroy(threadpool_t *pool)
{
	if (pool == NULL)
	{
		return -1;
	}

	pool->shutdown = true;
	//adjust_tid exit first
	pthread_join(pool->adjust_tid, NULL);
	// wake up the waiting thread
	pthread_cond_broadcast(&(pool->queue_not_empty));
	for (int i = 0; i < pool->min_thr_num; i++)
	{
		pthread_join(pool->threads[i], NULL);
	}
	threadpool_free(pool);
	return 0;
}

int threadpool_free(threadpool_t *pool)
{
	if (pool == NULL)
	{
		return -1;
	}
	if (pool->task_queue)
	{
		free(pool->task_queue);
	}
	if (pool->threads)
	{
		free(pool->threads);
		pthread_mutex_lock(&(pool->lock));
		pthread_mutex_destroy(&(pool->lock));
		pthread_mutex_lock(&(pool->thread_counter));
		pthread_mutex_destroy(&(pool->thread_counter));
		pthread_cond_destroy(&(pool->queue_not_empty));
		pthread_cond_destroy(&(pool->queue_not_full));
	}
	free(pool);
	pool = NULL;
	return 0;
}

int threadpool_all_threadnum(threadpool_t *pool)
{
	int all_threadnum = -1;
	pthread_mutex_lock(&(pool->lock));
	all_threadnum = pool->live_thr_num;
	pthread_mutex_unlock(&(pool->lock));
	return all_threadnum;
}

int threadpool_busy_threadnum(threadpool_t *pool)
{
	int busy_threadnum = -1;
	pthread_mutex_lock(&(pool->thread_counter));
	busy_threadnum = pool->busy_thr_num;
	pthread_mutex_unlock(&(pool->thread_counter));
	return busy_threadnum;
}

bool is_thread_alive(pthread_t tid)
{
	int kill_rc = pthread_kill(tid, 0);
	if (kill_rc == ESRCH)
	{
		return false;
	}
	return true;
}

void *process(void *arg)
{
	printf("thread 0x%x working on task %d\n ",pthread_self(),*(int *)arg);
	sleep(1);
	printf("task %d is end\n",*(int *)arg);
	return NULL;
}
int main()
{
	threadpool_t *thp = threadpool_create(3,100,12);
	printf("pool inited");

	int *num = (int *)malloc(sizeof(int)*20);
	for (int i=0;i<10;i++)
	{
		num[i]=i;
		printf("add task %d\n",i);
		threadpool_add(thp,process,(void*)&num[i]);
	}
	sleep(10);
	threadpool_destroy(thp);
}
