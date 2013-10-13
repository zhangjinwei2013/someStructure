#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRSIZE 2
/*insert sort*/
void insertSort(int array[])
{
    int i = 0,j = 0;
    int key;
    for ( j = 1; j < ARRSIZE; j++)
    {   
        key = array[j];
        i = j-1;
        while ( i > -1 && array[i] > key)
        {
            array[i+1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
    }
}

/*linear search*/
void lineSearch(int array[],int index)
{
    int i = -1;
    for (int i = 0; i < ARRSIZE; i++)
    {
        if (index == array[i])
            return i;
    }
    return i;
}

int main()
{
    int arr[ARRSIZE] = {3,2};
    int i = 0;
    printf("not sort\n");
    for ( i =0 ; i < ARRSIZE; i++)
        printf("array[%d] = %d\n",arr[i]);
    insertSort(arr);
    printf("insert sort\n");
    for ( i =0 ; i < ARRSIZE; i++)
        printf("array[%d] = %d\n",arr[i]);
    return 0;
}
