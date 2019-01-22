#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;

	
	

void *thread_routine1(void *arg1)
{

int *pt;
pt = (int*)arg1;
cout <<*pt <<endl;
pthread_exit(NULL);
}

void *thread_routine2(void *arg1)
{
cout <<"World" << endl;
pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	
	int *ptr;
	int x = 10;
	ptr = &x;

	cout <<"\nMain process had PID="<< getpid() <<endl;

	/*create thread */

	int t1=pthread_create(&thread1, NULL,thread_routine1,(void*)ptr);
		if(t1 == 0)
		{
			cout <<"Thread1 is created!" <<endl;
		}else{
			cout <<"Thread1 Failed!!!" <<endl;
		}
	pthread_join(thread1, NULL);
	int t2=pthread_create(&thread2, NULL,thread_routine2,NULL);

		if(t2 == 0)
		{
			cout <<"Thread2 is created!" <<endl;
		}else{
			cout <<"Thread2 Failed!!!" <<endl;
		}
	

	
	pthread_join(thread2, NULL);

	cout <<"Main thread is finished" <<endl;
	cout <<endl;
	pthread_exit(NULL);


}
