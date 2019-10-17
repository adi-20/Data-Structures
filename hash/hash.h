#ifndef _HASH_NS7_
#define _HASH_NS7_
#include <stdint.h>

typedef struct _node_link_ List;
typedef struct _hash_table_ HashTable;

struct _node_link_ {
    char data[50];
    List *next;
};

struct _hash_table_ {
    uint32_t size;
    List **addr_list;
};

HashTable hashtable_new(uint32_t size);
uint32_t hashtable_lookup(HashTable *ht, char * element);
HashTable* hashtable_add_key(HashTable *ht,char* element);
HashTable* hashtable_delete_key(HashTable *ht,char *element);
void hashtable_destroy(HashTable *ht);

#endif