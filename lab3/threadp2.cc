#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;

	
	

void *thread_routine(void *arg1)
{

int *pt;
pt = (int*)arg1;
cout <<"Hello World (thread "<<*pt<<")" <<endl;
pthread_exit(NULL);
}


int main()
{

	pthread_t threads[10];
	
	

	for(int x=0; x<10; x++)
	{
	int *ptr;
	int a = x;
	ptr = &a;
	pthread_create(&threads[x], NULL,thread_routine,(void*)ptr);
	pthread_join(threads[x], NULL);
	}	

	pthread_exit(NULL);


}
