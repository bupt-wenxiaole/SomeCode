/**********************************************
 子线程循环 10 次，接着主线程循环 100 次，
 接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，
 如此循环50次，试写出代码。
 ************************************************/


#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 
#include <string.h>



pthread_mutex_t mutex;
pthread_cond_t cond;
 
enum  Statu{ Main=0,Son=1,ThreadNum };
enum Statu Running=Son;/* 其值若为 Main,则表明 Main 开始运行. */
const int loop_times=50;
 
void* son_thread(void * arg){
    pthread_mutex_lock(&mutex);
    for(int ci=0;ci<loop_times;){
        if(Running==Son){
            for(int cj=0;cj<10;++cj);
            printf("%d\n: 子线程循环 10 次",ci);
            Running=Main;
            ++ci;
        }
        pthread_cond_signal(&cond);  //向等待cond的线程发消息
        pthread_cond_wait(&cond,&mutex);//注意wait函数，当等待cond时线程阻塞，对mutex解锁。当收到信号时，wait返回，同时对mutex 加锁
    }
    pthread_mutex_unlock(&mutex);      //最后一次退出线程,可以在纸上模拟
    pthread_cond_signal(&cond);
    pthread_exit(NULL);
}
 
void* main_thread(void * arg){
    pthread_mutex_lock(&mutex);
    for(int ci=0;ci<loop_times;){
        if(Running==Main){
            for(int cj=0;cj<100;++cj);
            printf("%d\n: 主线程运行 100 次",ci);
            Running=Son;
            ++ci;
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond,&mutex);
    }
    pthread_mutex_unlock(&mutex);     
    pthread_cond_signal(&cond);
    pthread_exit(NULL);
}
 
int main(int argc,char *argv[]){
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);
 
    pthread_t threads[ThreadNum];
    pthread_create(&threads[Main],NULL,main_thread,NULL);
    pthread_create(&threads[Son],NULL,son_thread,NULL);
    pthread_join(threads[Main],NULL);
    pthread_join(threads[Son],NULL);
    return 0;
}
