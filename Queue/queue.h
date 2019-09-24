#ifndef _NS_QUEUE_LIST_
#define _NS_QUEUE_LIST_

#include<stdint.h>
#include "../comm.h"
#include "../assignement2/support_3.h"

#define STATUS_OK 1
#define STATUS_FAIL 0
#define MAX_SIZE 50

typedef struct __queue__ Queue;

struct __queue__{
	uint32_t size;
	DATA_TYPE_USED data[MAX_SIZE];
	int32_t top;
	uint32_t bottom;
	uint32_t length;
};

Queue* create_queue();
uint32_t length(Queue* queue);
OprResult* add(Queue* queue,DATA_TYPE_USED data);
OprResult* delete(Queue* queue);
OprResult* search(Queue* queue);


#endif