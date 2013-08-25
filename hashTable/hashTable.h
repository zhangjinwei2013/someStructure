#ifndef __HASHTABLE_H
#define __HASHTABLE_H

typedef struct dictEntry
{
    void *key;
    enum
    {
        void *val;
        uint64_t u64;
        int64_t s64;
    }v;
    dictEntry *next;
};

typedef struct dictType
{
    unsigned int (*hashFunction)(const void *key);
};

typedef struct dictht
{
    ditcEntry **table;
    unsigned long size;
    unsigned long sizeumask;
    unsigned long used;
};

typedef struct dict
{
    dictType *type;
    void *privateData;
    dictht ht[2];
    int rehashidx;
    int iterators;
};

/*API*/
dict *dictCreate(dictType *type, void *privateData);
int dictAdd(dict *d,void *key, void *val);
int dictDelete(dict *d, const void *key);
int dictReplace(dict *d, void *key, void *val);
dictEntry *dictFind(dict *d, const void *key);
void *dictFetchValue(dict *d, const void *key);
void dictRelease(dict *d);
void dictEmpty(dict *d);
int dictResize(dict *d);
int dictExpand(dict *d);

#endif //__HASHTABLE_H
