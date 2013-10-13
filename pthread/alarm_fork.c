#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>
#include <wait.h>

#define MS 512

int main()
{
    int seconds;
    char msg[MS];
    char line[MS];
    pid_t pid;
    while (1)
    {
        printf("alarm\n");
        if (fgets(line,sizeof(line),stdin) == NULL)
            exit(EXIT_FAILURE);
        if (strlen(line) < 1)
            continue;
        if (sscanf(line,"%d %64[^\n]",&seconds,msg) < 2)
            printf("bad input\n");
        else
        {
            pid = fork();
            if (pid == (pid_t)-1)
            {
                printf("fork\n");
                exit(EXIT_FAILURE);
            }
            else if (pid == (pid_t)0) //child process
            {
                printf("msg=%s\n",msg);
                sleep(seconds);
            }
            else
            {
                do {
                    pid = waitpid((pid_t)-1,NULL,WNOHANG);
                    if (pid == (pid_t)-1)
                    {
                        printf("waitpid\n");
                        exit(EXIT_FAILURE);
                    }
                } while(pid != (pid_t)0)
            }
        }
    }
    exit(EXIT_SUCCESS);
}
