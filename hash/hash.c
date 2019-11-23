#include<stddef.h>
#include <stdlib.h>
#include<stdint.h>
#include<assert.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

HashTable hashtable_new(uint32_t size){
    // HashTable *h = (HashTable*) malloc(sizeof(HashTable));
    HashTable ht;// = *h;
    ht.size = size;
    ht.addr_list = (Link**) malloc(ht.size * sizeof(Link*));
    for(int i = 0;i<ht.size;i++){
        ht.addr_list[i] = NULL;
    }
    ht.no_elements = 0;
    return ht;
}

static int32_t _hash_code_(char element[]){
    int32_t number = 0;
    while(*element!='\0'){
        number =(number<<5)+ *element++;
    }
    return number;
}
static uint32_t _compression_(uint32_t size, int32_t hash_code){
    return (hash_code%size);
}
static uint32_t _hash_(uint32_t size,char* element){
    int32_t num = _hash_code_(element);
    return ( _compression_(size,num) );
}

uint32_t hashtable_lookup(HashTable *ht,char element[]){
    assert(ht!=NULL);
    // Retriving link of the hash code 
    Link *cur = ht->addr_list[_hash_(ht->size,element)];

    // Searching for the element in the linked list
    while(cur!=NULL){
        if(!strcmp(cur->data,element)){
            // element found then get out saying element is identified
            break;
        }else{
            // Traversing to next element in linked list
            cur = cur->next;
        }
    }
    // element if identified or not identified(not identified mean the curr is out of linked list which means  it is NULL)
    return cur!=NULL;
}

HashTable* hashtable_add_key(HashTable *ht,char element[]){
    assert(ht!=NULL);
    uint32_t bucket = _hash_(ht->size,element);
    if(!hashtable_lookup(ht,element)){
        Link *old_Address = ht->addr_list[bucket];
        ht->addr_list[bucket] = (Link*) malloc(sizeof(Link));
        strcpy(ht->addr_list[bucket]->data,element);
        ht->addr_list[bucket]->next = old_Address;
        ht->no_elements++;
    }
    return ht;
}

HashTable* hashtable_delete_key(HashTable *ht,char element[]){
    assert(ht!=NULL);
    uint32_t bucket = _hash_(ht->size,element);
    Link* lnk = ht->addr_list[bucket];
    Link** prnt = &(ht->addr_list[bucket]);

    //Traversing to the location
    while(lnk!=NULL && strcmp(lnk->data,element)!=0){
        prnt = &(lnk->next);
        lnk = lnk->next;
    }

    // Checking if element is identified
    if(lnk!=NULL){
        *prnt = lnk->next;
        free(lnk);
        ht->no_elements--;
    }
    return ht;
}

void hashtable_destroy(HashTable *ht){
    assert(ht!=NULL);
    Link *curr,*temp;

    for(int i=0;i<ht->size;i++){
        curr = ht->addr_list[i];
        while(curr!=NULL){
            temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(ht->addr_list);
}

int main(int v,char** c){
    HashTable ht = hashtable_new(4);
    assert(ht.size ==4);
    for( int i = 0;i<ht.size;i++){
        assert(ht.addr_list[i]==NULL);
    }
    char a[10]="naren";
    int val = _hash_code_(a);
    int comp = _compression_(4,val);
    printf("\n%d",_hash_(10,a));
    printf("\n%d",comp);
    HashTable *hashtable = &ht;
    val = hashtable_lookup(hashtable,"naren");
    assert(val==0);
    hashtable_add_key(hashtable,"naren");
    val = hashtable_lookup(hashtable,"naren");
    assert(val==1);
    hashtable_delete_key(hashtable,"naren");
    val = hashtable_lookup(hashtable,"na121ren");
    assert(val==0);
    hashtable_delete_key(hashtable,"nar1231en");

    hashtable_add_key(hashtable,"naren");
    hashtable_add_key(hashtable,"ajith");
    hashtable_add_key(hashtable,"pinaka");
    hashtable_add_key(hashtable,"wajoud");
    hashtable_add_key(hashtable,"adlen");
    hashtable_add_key(hashtable,"deva");
    hashtable_add_key(hashtable,"amrutha");
    hashtable_add_key(hashtable,"anupam");
    hashtable_add_key(hashtable,"anagha");
    hashtable_add_key(hashtable,"atton");
    // hashtable_add_key(hashtable,"shaheel");
    val = hashtable_lookup(hashtable,"atton");
    assert(val==1);
    val = hashtable_lookup(hashtable,"adlen");
    assert(val==1);
    val = hashtable_lookup(hashtable,"naren");
    assert(val==1);
    val = hashtable_lookup(hashtable,"deva");
    assert(val==1);
    val = hashtable_lookup(hashtable,"amrutha");
    assert(val==1);
    val = hashtable_lookup(hashtable,"anagha");
    assert(val==1);
    val = hashtable_lookup(hashtable,"pinaka");
    assert(val==1);
    val = hashtable_lookup(hashtable,"wajoud");
    assert(val==1);
    val = hashtable_lookup(hashtable,"shaheel");
    assert(val==0);

}