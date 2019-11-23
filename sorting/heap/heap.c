#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "heap.h"

static OprResult* create_result(int32_t data,int32_t status){
    OprResult* res = (OprResult*) malloc(sizeof(OprResult));
    res->data = data;
    res->status = status;
    return res;
}
static void swap(int32_t* a,int32_t* b){
    int32_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//Checking is parent is greater than children
void __heapify__(int32_t *data,uint32_t size,int32_t parent){
    int32_t children = 2*parent;
    while(children<=size){
        // 1. Find the highest value of the children
        if(children+1<=size && data[children+1]>data[children]){
            children++;
        }

        // 2. Compare the hightest child value with the parent
        if(data[parent]>=data[children]){
            break;
        }
        swap(&data[parent],&data[children]);

        // now make the child as parent and validate for the below graph
        parent = children;
        children = 2 * parent;
    }
}

Heap create_heap(int32_t data[],uint32_t size){
    //Create a copy of data
    // int32_t  arr[size+1];
    int32_t *tmp_data = (int32_t*) malloc(size * sizeof(int32_t));
    memcpy(tmp_data,data,size*sizeof(int32_t));

    for(int parent = size/2;parent>=1;--parent){
        __heapify__(tmp_data,size,parent);
    }

    Heap heap;
    heap.size = size;
    heap.data = tmp_data;
    heap.actual_size = size;
    return heap;
}

OprResult* heap_add(Heap *heap,int32_t data){
    // Creating size+1 
    int32_t *tmp_arr;
    if(heap->actual_size<=heap->size){
        tmp_arr = (int32_t*) malloc((heap->size+1)*sizeof(int32_t));
        memcpy(tmp_arr,heap->data, heap->size * sizeof(int32_t));
    }else{
        tmp_arr = heap->data;
    }
    int32_t *ptr = heap->data;
    tmp_arr[heap->size]= data;
    heap->size++;
    heap->actual_size = heap->size;
    for(uint32_t parent=heap->size/2;parent>0;parent--)
        __heapify__(tmp_arr,heap->size,parent);
    heap->data = tmp_arr;
    free(ptr);
    return create_result(data,STATUS_OK);
}

OprResult* heap_delete(Heap* heap){
    OprResult *res;
    if(heap->size!=1){
        res =create_result(heap->data[1],STATUS_OK);
        heap->data[1] = heap->data[heap->size-1];
        heap->size = heap->size-1;
        __heapify__(heap->data,heap->size,1);

    }else{
        res =create_result(-1,STATUS_FAIL);
    }
    return res;
}
OprResult* height(Heap* heap){
    int parent = heap->size-1;
    int height = 0;
    while(parent>=1){
        height++;
        parent = parent/2;
    }
    return create_result(height,STATUS_OK);
}
OprResult* isTreeFull(Heap* heap){
    int hght = height(heap)->data;
    int expt_size = pow(2,hght);
    if(expt_size==heap->size){
        return create_result(1,STATUS_OK);
    }
    return create_result(0,STATUS_OK);
}
