#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;
int x,total = 0;
pthread_mutex_t amutex = PTHREAD_MUTEX_INITIALIZER;
int rc;
void *thread_routine1(void *arg1)
{	
	//Locks the Thread.
	pthread_mutex_lock(&amutex); 
	for(int i = 0; i<100000; i++)
	x += 1;
	cout << x << endl;
	//Unlock thread so other thread can use the gobal variable x
	pthread_mutex_unlock(&amutex);
}
void *thread_routine2(void *arg1)
{	
	pthread_mutex_lock(&amutex);
	for(int i = 0; i<100000; i++)
	x += 2;
	pthread_mutex_unlock(&amutex);
}
int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL,thread_routine1,NULL);
	pthread_create(&thread2, NULL,thread_routine2,NULL);	
	cout <<endl;
	for(int k = 0; k<10000000; k++)
	total = total +1;
	cout << "Thread1 + Thread2 produced: " << x << endl;
	pthread_exit(NULL);
}
