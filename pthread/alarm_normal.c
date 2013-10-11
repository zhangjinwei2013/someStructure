#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define SIZE 512

int main()
{
    char line[SIZE] = {0};
    int seconds;
    char msg[SIZE];
    while (1)
    {
        printf("alarm\n");
        if (fgets(line,sizeof(line),stdin) == NULL)
            return -1;
        if (strlen(line) <= 1)
            continue;
        if (sscanf(line,"%d %64[^\n]",&seconds,msg) < 2)
        {       
            printf("sorry,bad command\n");
            return -1;
        }
        else
        {
            printf("msg,%s\n",msg);
            sleep(seconds);
        }
    }
}
