#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;

	
	

void *thread_routine(void *arg1)
{

char *pt;
pt = (char*)arg1;
cout << *pt;
pthread_exit(NULL);
}


int main()
{
	pthread_t thread1;
	pthread_t thread2;
	

	char hello[] = "hello";
	char world[] = "world";

	char *x;
	char *y;
	x = &hello[0];
	y = &world[0];
	
	
	for(int i=0;i<5;i++)
	{
	pthread_create(&thread1, NULL,thread_routine,(void*)x);
	pthread_join(thread1, NULL); //Waits for the thread to finish before it goe on through main.
	x++;
	}
	for(int i=0;i<5;i++)
	{
	pthread_create(&thread2, NULL,thread_routine,(void*)y);
	pthread_join(thread2, NULL);
	y++;
	}
	
	cout <<endl;
	cout <<endl;
	pthread_exit(NULL);


}
