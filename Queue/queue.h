#ifndef _NS_QUEUE_LIST_
#define _NS_QUEUE_LIST_
#include<stdint.h>

#define STATUS_OK 1
#define STATUS_FAIL 0
#define MAX_SIZE 50

typedef struct __queue__ Queue;
typedef struct __opr_result__ OprResult;

struct __queue__{
	uint32_t size;
	int32_t data[MAX_SIZE];
	int32_t top;
	uint32_t bottom;
	uint32_t length;
};

struct __opr_result__
{
	uint32_t status;
	int32_t data;
};

Queue* create_queue();
uint32_t length(Queue* queue);
OprResult* add(Queue* queue,uint32_t data);
OprResult* delete(Queue* queue);
OprResult* search(Queue* queue);


#endif