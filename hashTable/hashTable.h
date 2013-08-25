#include <stdint.h>
#ifndef __HASHTABLE_H
#define __HASHTABLE_H

typedef struct dictEntry
{
    void *key;
    union
    {
        void *val;
        uint64_t u64;
        int64_t s64;
    }v;
    struct dictEntry *next;
}dictEntry;

typedef struct dictType
{
    unsigned int (*hashFunction)(const void *key);
}dictType;

typedef struct dictht
{
    dictEntry **table;
    unsigned long size;
    unsigned long sizeumask;
    unsigned long used;
}dictht;

typedef struct dict
{
    dictType *type;
    void *privateData;
    dictht ht[2];
    int rehashidx;
    int iterators;
}dict;

extern dict *dictCreate(dictType *type, void *privateData);
extern int dictAdd(dict *d,void *key, void *val);
extern int dictDelete(dict *d, const void *key);
extern int dictReplace(dict *d, void *key, void *val);
extern dictEntry *dictFind(dict *d, const void *key);
extern void *dictFetchValue(dict *d, const void *key);
extern void dictRelease(dict *d);
extern void dictEmpty(dict *d);
extern int dictResize(dict *d);
extern int dictExpand(dict *d);

#endif //HASHTABLE_H
