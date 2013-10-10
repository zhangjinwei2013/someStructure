#include <stddef.h>
#include "hashTable.h"
#include "zmalloc.h"

#define DICT_OK 0

#define dictIsRehashing(ht) ((ht)->rehashidx != -1)

static int _dictInit(dict *d, dictType *type, void *privateData);

dict *dictCreate(dictType *type, void *privateData)
{
    dict *d = zmalloc(sizeof(*d));
    _dictInit(d,type,privateData);
    return d;    
}

_dictReset(dictht *ht)
{
    ht->table = NULL;
    ht->size  = 0;
    ht->sizeumask = 0;
    ht->used = 0;
}

int _dictInit(dict *d, dictType *type, void *privateData)
{
    _dictReset(&d->ht[0]);//d->ht[0]的type 为 dichht
    _dictReset(&d->ht[1]);
    d->type = type;
    d->privateData = privateData;
    d->rehashidx = -1;
    d->iterators = 0;
    return DICT_OK;
}

dictEntry *_dictAddRaw(dict *d,void *key)
{
    
}

int dictAdd(dict *d, void *key, void *val)
{
    dictEntry *entry = _dictAddRaw(d,key);
    return DICT_OK;
}
