#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 32

#define TAKEOFF 0
#define LANDING 1

typedef struct _event_ Event;
struct _event_{
	uint32_t timestamp;
	uint32_t plane_no;
	uint32_t t_or_l;
};

typedef struct _heap_ Heap;
struct  _heap_
{
	uint32_t	size;
	Event **data;
};

Heap 		heap_new(Event **data, uint32_t len);
Heap*		heap_sort(Heap *heap);
Heap*		heap_insert(Heap *heap, Event *key);
void		heap_test(Heap *heap);
Event*		heap_get_min(Heap *heap);
Event*		heap_extract_min(Heap *heap);
uint32_t	heap_size(Heap *heap);

#endif