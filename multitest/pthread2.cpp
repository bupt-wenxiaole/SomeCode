/***************************************************************************
编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C,每个线程将自己的ID在屏幕上打印10遍，
要求输出结果必须按ABC的顺序显示；如：ABCABC…依次递推。
****************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 
#include <string.h>


pthread_mutex_t mutex;
pthread_cond_t cond;
int num=0;

void * func1(void *)
{
    pthread_mutex_lock(&mutex);
    for (int i=0;i<10;)
    {
        if(num==0)
        {
            printf("A\n");
            num=1;
            i++;
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond,&mutex);

    }
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    pthread_exit(NULL);
}
void * func2(void *)
{
    pthread_mutex_lock(&mutex);
    for (int i=0;i<10;)
    {
        if(num==1)
        {
            printf("B\n");
            num=2;
            i++;
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond,&mutex);

    }
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    pthread_exit(NULL);
}

void * func3(void *)
{
    pthread_mutex_lock(&mutex);
    for (int i=0;i<10;)
    {
        if(num==2)
        {
            printf("C\n");
            num=0;
            i++;
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond,&mutex);

    }
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);
    pthread_t threads[3];
    pthread_create(&threads[0],NULL,func1,NULL);
    pthread_create(&threads[1],NULL,func2,NULL);
    pthread_create(&threads[2],NULL,func3,NULL);
    for(int i=0;i<3;i++)
        pthread_join(threads[i],NULL);
    return 0;
}
