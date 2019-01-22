#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;
	int x,total = 0;
void *thread_routine1(void *arg1)
{	
	for(int i = 0; i<100000; i++)
	x += 1;
	cout << x << endl;
}
void *thread_routine2(void *arg1)
{	
	for(int i = 0; i<100000; i++)
	x += 2;
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
