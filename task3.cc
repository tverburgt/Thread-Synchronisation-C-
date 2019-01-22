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
	cout <<"\nEnter a message: ";
	getline(cin,message);
	pthread_mutex_unlock(&mymutex);
	}
}
void *print_routine(void *arg1)
{	
	
	while(1){
	pthread_mutex_lock(&mymutex);
	cout <<"Message: "<<message<<endl;
	pthread_mutex_unlock(&mymutex);
	}
}
int main()
{	
	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1, NULL,input_routine,NULL);
	pthread_create(&thread2, NULL,print_routine,NULL);
	
	pthread_exit(NULL);
}
