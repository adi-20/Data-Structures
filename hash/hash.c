#include<stddef.h>
#include <stdlib.h>
#include<stdint.h>
#include<assert.h>
#include <stdio.h>
#include "hash.h"

HashTable hashtable_new(uint32_t size){
    // HashTable *h = (HashTable*) malloc(sizeof(HashTable));
    HashTable ht;// = *h;
    ht.size = size;
    ht.addr_list = (List**) malloc(ht.size * sizeof(List*));
    for(int i = 0;i<ht.size;i++){
        ht.addr_list[i] = NULL;
    }
    return ht;
}

static int32_t _hash_code_(char *element){
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

int main(int v,char** c){
    HashTable ht = hashtable_new(10);
    assert(ht.size ==10);
    for( int i = 0;i<ht.size;i++){
        assert(ht.addr_list[i]==NULL);
    }
    char a[10]="naren";
    int val = _hash_code_(a);
    int comp = _compression_(10,val);
    printf("\n%d",_hash_(10,a));
    printf("\n%d",comp);
}