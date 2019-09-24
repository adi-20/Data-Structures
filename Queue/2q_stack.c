#include<stdio.h>
#include<assert.h>

#include "queue.h"

OprResult* push(Queue* q,DATA_TYPE_USED data){
	return add(q,data);
}

Queue* pop(Queue* q){
	int len = length(q);
	OprResult* res = NULL;
	Queue* q2 = create_queue(q->size);
	for(int i =0;i<len-1;i++){
		res = delete(q);
		add(q2,res->data);
	}
	res = delete(q);
	return q2;
}



void main(){
	Queue* q = create_queue(10);
	OprResult* res = push(q,1);
	res = push(q,2);
	res = push(q,3);
	res = push(q,4);
	assert(length(q)==4);
	q = pop(q);
	assert(length(q)==3);
	q = pop(q);
	assert(length(q)==2);

}