#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "heap.h"


static void _swap_(Event *data1, Event *data2) {

	uint32_t timestamp = data1->timestamp;
	uint32_t plane_no = data1->plane_no;
	uint32_t t_or_l = data1->t_or_l;

	data1->timestamp = data2->timestamp;
	data1->plane_no = data2->plane_no;
	data1->t_or_l = data2->t_or_l;

	data2->timestamp = timestamp;
	data2->plane_no = plane_no;
	data2->t_or_l = t_or_l;
	
}

static void copy_event(Event *data_from,Event *data_to){

	data_to->timestamp = data_from->timestamp;
	data_to->plane_no = data_from->plane_no;
	data_to->t_or_l = data_from->t_or_l;

}



static void _heapify_ (Event **data, uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (data[child+1]->timestamp < data[child]->timestamp){
				++child;
			}
		}
		if (data[parent]->timestamp <= data[child]->timestamp) {
			break;
		}
		_swap_(data[parent], data[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_heap_(Event **data, uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child]->timestamp >= data[child/2]->timestamp);
	}

}

void heap_test(Heap *heap)
{
	_test_heap_(heap->data, heap->size);
}

Heap heap_new(Event **data, uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		printf("\nlol : %d\n",data[idx]->timestamp);
		_heapify_(data, len, idx);
	}

	heap.size = len;
	memcpy(heap.data, data, (len+1) * sizeof(int32_t));
	_test_heap_(heap.data, heap.size);

	return heap;
}

Heap*	heap_sort(Heap *heap) {
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = heap->size;

	for (idx = heap->size; idx > 1; idx--) {
		_swap_(heap->data[idx], heap->data[1]);
		_heapify_(heap->data, idx-1, 1);
	}

	return heap;
}


Heap*	heap_insert(Heap *heap, Event *key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);
	// printf("\n%d\t%d\t%d\n",key->timestamp,key->plane_no,key->t_or_l);
	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;
	copy_event(key,heap->data[loc]);
	
	while( loc > 1 && heap->data[parent]->timestamp > key->timestamp) {
		_swap_(heap->data[loc],heap->data[parent]); // heap->data[loc] = heap->data[parent];
		loc = parent;
		parent = parent/2;
	}
	 //heap->data[loc] = key;
	return heap;

}

Event*	heap_get_min(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->data[1];
}

Event* heap_extract_min(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	Event max = *(heap->data[1]);	
	_swap_(heap->data[1], heap->data[heap->size]);
	--heap->size;
	_heapify_(heap->data, heap->size, 1);
	return &max;
}

uint32_t	heap_size(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}