#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "queue.h"

Queue* create_queue(uint32_t size){
	// size = size>MAX_SIZE? MAX_SIZE:size;
	if(size>MAX_SIZE){
		size = MAX_SIZE;
	}
	Queue* q = (Queue*) malloc(sizeof(Queue));
	q->size = size;
	q->top = -1;
	q->bottom = 0;
	q->length = 0;
	return q;
}

static OprResult* create_result(uint32_t status){
	OprResult* res = (OprResult*) malloc(sizeof(OprResult));
	res->status = status;
	return res;
}
uint32_t length(Queue* q){
	return q->length;
}

OprResult* add(Queue* q,DATA_TYPE_USED data){
	assert(q!=NULL);
	OprResult* res = NULL;
	if(q->length+1 > q->size){
		res = create_result(STATUS_FAIL);
	}else{
		q->top = (++q->top)%(q->size);
		q->data[q->top] = data;
		q->length++;
		res = create_result(STATUS_OK);
		res->data = data;
	}
	return res;

}

OprResult* delete(Queue* q){
	assert(q!=NULL);
	OprResult* res = NULL;
	if(q->length==0){
		res = create_result(STATUS_FAIL);
	}else{
		DATA_TYPE_USED data = q->data[q->bottom];
		q->length--;
		q->bottom = (q->bottom+1)%(q->size);
		res = create_result(STATUS_OK);
		res->data = data;
	}
	return res;
}

// void display(Queue* q){
	
// }


