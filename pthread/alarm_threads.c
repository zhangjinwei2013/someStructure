#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <pthread.h>

#define SIZE 512

typedef struct __AlarmTAG
{
    int seconds;
    char msg[SIZE];
}TAlarm;

void *func(void *arg)
{
    TAlarm * alarm = (TAlarm *)arg;
    int status = pthread_detach(pthread_self());//recovery resources when thread is over
    if (status != 0)
    {
        printf("detach\n");
        exit(EXIT_FAILURE);
    }
    printf("msg=%s\n",alarm->msg);
    sleep(alarm->seconds);
    exit(EXIT_SUCCESS);
}

int main()
{
    char line[SIZE] = {0};
    int rv = 0;
    pthread_t pthread;
    TAlarm alarm;
    while (1)
    {
        printf("alarm\n");
        if (fgets(line,sizeof(line),stdin) == NULL)
            return -1;
        if (strlen(line) <= 1)
            continue;
        if (sscanf(line,"%d %64[^\n]",&(alarm.seconds),alarm.msg) < 2)
        {       
            printf("sorry,bad command\n");
            return -1;
        }
        else
        {
            rv = pthread_create(&pthread,NULL,func,&alarm);
            if (rv != 0)
            {
                printf("create\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    exit(EXIT_SUCCESS);
}
