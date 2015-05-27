/************************************************************
 * A sample to solve the producer and consumer problem in  **
 * the linux environment                                   **
 * **********************************************************/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define MAXSIZE 5             /*共享缓冲区的大小*/
//共享数据，使用互斥锁限制线程对这些数据的访问
int sharedArray[MAXSIZE];       /*sharedArray是共享缓冲区*/
int curr=-1;                     /*curr是用来指定sharedArray当前存有数据的最大位置*/

                                 /*注意,sharedArray和curr都属于共享数据*/

int empty=0;          
int full=MAXSIZE;

pthread_mutex_t    sharedMutex=PTHREAD_MUTEX_INITIALIZER; /*锁定临界区的mutex*/
sem_t    waitNonEmpty, waitNonFull; /*等待"非空资源"和等待"非满资源"的semaphor*/

//消费者
void *  readData(void * whichone)
{
	int data, position;

	while (1){
		sem_wait(&waitNonEmpty);             /*是否有"非空资源"*/
		pthread_mutex_lock(&sharedMutex);   /*进入临界区*/

		data = sharedArray[curr];

		position = curr--;

		printf ("%s read from the %dth: %d, \n", (char*)whichone, position, data);

		sem_post(&waitNonFull);              /*生成一个"非满资源"*/

		pthread_mutex_unlock(&sharedMutex); /*离开临界区*/

		sleep(2);                            /*跟同步无关的费时操作*/
	}
}

//生产者
void * writeData(void * whichone)
{
	int data, position;

	while (1) {
		data=(int)(10.0*random()/RAND_MAX);   /*生成一个随机数据,注意是10.0而不是10*/
		sem_wait(&waitNonFull );                /*是否有"非满资源"*/
		pthread_mutex_lock(&sharedMutex);      /*进入临界区*/

		position = ++curr;

		sharedArray[curr]=data;

		printf ("%s wrote to the %dth: %d, \n", (char*)whichone, position, data);

		sem_post(&waitNonEmpty);               /*生成一个"非空资源"*/

		pthread_mutex_unlock(&sharedMutex);   /*离开临界区*/
		sleep(1);                            /*跟同步无关的费时操作*/
	}
}

int main (int argc, char** argv)
{
	pthread_t consumer1, consumer2, producer1, producer2;   /*两个生产者和两个消费者*/
	sem_init(&waitNonEmpty, 0, empty);                       /*初始化信号量*/
	sem_init(&waitNonFull, 0, full);          

	/*注意,本问题中的两种semaphore是有一定关系的,那就是它们的初始值之和应该等于共享缓冲区大小*/
	/*即empty+full等于MAXSIZE*/

	pthread_create (&consumer1, NULL, &readData, "consumer1");
	pthread_create (&consumer2, NULL, &readData, "consumer2");
	pthread_create (&producer1, NULL, &writeData, "producer1");
	pthread_create (&producer2, NULL, &writeData, "producer2");

	pthread_join (consumer1, NULL);
	pthread_join (consumer2, NULL);
	pthread_join (producer1, NULL);
	pthread_join (producer2, NULL);

	sem_destroy(&waitNonEmpty);
	sem_destroy(&waitNonFull);
}

