#ifndef _HEAP_NS7_
#define _HEAP_NS7_

#include<stdint.h>
#include "../../comm.h"
typedef struct __heap__ Heap;

struct __heap__{
    uint32_t size;
    uint32_t actual_size;
    int32_t *data;
};

Heap create_heap(int32_t data[],uint32_t size);
OprResult* heap_add(Heap *heap,int32_t data);
OprResult* heap_delete(Heap *heap);
OprResult* height(Heap *heap);
OprResult* isTreeFull(Heap *heap);

#endif