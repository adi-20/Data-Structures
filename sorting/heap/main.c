#include <stdio.h>
#include <assert.h>

#include "heap.h"

void t_create_heap(){
    int a[]={0,1,5,2,4,6,3,9};
    Heap h= create_heap(a,2);
    assert(h.size==2);
    assert(h.data[0]==0);
    assert(h.data[1]==1);

    h= create_heap(a,3);
    assert(h.size==3);
    assert(h.data[1]==5);
    assert(h.data[2]==1);

    h= create_heap(a,8);
    assert(h.size==8);
    assert(h.data[1]==9);
}

void t_add_heap(){
    int a[]={0, 1,5,2,4,6,3,9};
    Heap h= create_heap(a,8);
    Heap *heap =&h;
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }
    assert(h.data[1]==9);
    heap_add(heap,12);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }
    assert(h.data[1]==12);
    assert(h.data[2]==9);

    heap_add(heap,12);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }
    assert(h.data[1]==12);
    assert(h.data[2]==12);

}

void t_delete_heap(){
    printf("\n---Deleting---\n");
    int a[]={0,1,5,2,4,6,3,9};
    Heap h= create_heap(a,8);
    Heap *heap =&h;
    int size = h.size;
    heap_delete(heap);
    assert(size-1==h.size);
    assert(h.data[1]==6);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }

    size = h.size;
    heap_add(heap,12);
    assert(size+1==h.size);
    assert(h.data[1]==12);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }

    size = h.size;
    heap_delete(heap);
    assert(size-1==h.size);
    assert(h.data[1]==6);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }

    size = h.size;
    heap_delete(heap);
    assert(size-1==h.size);
    assert(h.data[1]==5);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }

    size = h.size;
    heap_delete(heap);
    assert(size-1==h.size);
    assert(h.data[1]==4);
    printf("\n%d\n",h.size);
    for(int i =1;i<h.size;i++){
        printf("%d ",h.data[i]);
    }
}

void t_height(){
    int a[]={0,1,5,2,4,6,3,9};
    Heap h= create_heap(a,8);
    Heap *heap =&h;
    assert(height(heap)->data==3);
    heap_delete(heap);
    assert(height(heap)->data==3);
    heap_delete(heap);
    assert(height(heap)->data==3);
    heap_delete(heap);
    assert(height(heap)->data==3);
    heap_delete(heap);
    assert(height(heap)->data==2);
}

void t_is_full(){
    int a[]={0,1,5,2,4,6,3,9};
    Heap h= create_heap(a,8);
    Heap *heap =&h;
    assert(isTreeFull(heap)->data==1);
    heap_delete(heap);
    assert(isTreeFull(heap)->data==0);
}

int main(int v,char ** c){
    t_create_heap();
    t_add_heap();
    t_delete_heap();
    t_height();
    t_is_full();
}