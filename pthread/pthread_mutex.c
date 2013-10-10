#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct MyData_TAG
{
	pthread_mutex_t mutex;
	int value;
}MyData_T;

MyData_T test = {PTHREAD_MUTEX_INITIALIZZER,0};

void *fun1(void *arg)
{
	for(int i = 1; i < 10;i++)
	{
		pthread_mutex_lock(&(test.mutex));
		test.value = i;
		printf("fun1 value = %d\n",test.value);
		pthread_mutex_unlock(&(test.mutex));
	}
	return NULL;
}

void *fun2(void *arg)
{
	for(int i = 11; i < 20;i++)
	{
		pthread_mutex_lock(&(test.mutex));
		test.value = i;
		printf("fun1 value = %d\n",test.value);
		pthread_mutex_unlock(&(test.mutex));
	}
	return NULL;
}

int main()
{
	pthread_t pthread1,pthread2;
	int rv;
	
	if (0 != pthread_mutex_init(&(test.mutex),NULL) )
	{
		printf("pthread_mutex_init failed\n");
		return -1;
	}
	if (0 != pthread_create(&pthread1,NULL,fun1,NULL) )
	{
		printf("pthread1 create failed\n");
		return -1;
	}
	if (0 != pthread_create(&pthread1,NULL,fun2,NULL) )
	{
		printf("pthread2 create failed\n");
		return -1;
	}
	pthread_join(&pthread1,NULL);
	pthread_join(&pthread2,NULL);

	pthread_mutex_destory(&(test.mutex));
	return 0;
}
