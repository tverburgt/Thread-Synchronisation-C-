#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;

	pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
	string message;
	int x = 0;

void *input_routine(void *arg1)
{	
	
	while(1){
	pthread_mutex_lock(&mymutex);
		if (x==0)
		{	
		cout <<"\nEnter a message: ";
		getline(cin,message);
		x = 1;
		}
	pthread_mutex_unlock(&mymutex);
	}
	
	//pthread_exit(NULL);
}
void *print_routine(void *arg1)
{	
	
	while(1){
	pthread_mutex_lock(&mymutex);
		if(x==1){
		cout <<"Message: "<<message<<endl;
		x = 0;
		}
	pthread_mutex_unlock(&mymutex);
	}
	
	//pthread_exit(NULL);
}
int main()
{	
	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1, NULL,input_routine,NULL);
	pthread_create(&thread2, NULL,print_routine,NULL);
	
	
	
	pthread_exit(NULL);
}
