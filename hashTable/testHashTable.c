#include <stdio.h>
#include "hashTable.h"

int main()
{
    dictType *type = NULL;
    void *privateData = NULL;
    dict *d = dictCreate(type,privateData);
    return 0;
}
