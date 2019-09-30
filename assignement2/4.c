/*
    Design a stack using a single queue as an instance variable, and only constant additional local
    memory within the method bodies.
*/

#include<stdio.h>
#define DATA_TYPE_USED int
#include<assert.h>

#include "../comm.h"
#include "../Queue/queue.h"

OprResult* push(Queue* q,DATA_TYPE_USED data){
	return add(q,data);
}

OprResult* pop(Queue* q){
	int len = length(q);
	OprResult* res = NULL;
	Queue* q2 = create_queue(q->size);
	for(int i =0;i<len-1;i++){
		res = delete(q);
		add(q2,res->data);
	}
	OprResult* result = delete(q);
    for(int i = 0;i<len-1;i++){
        res = delete(q2);
		add(q,res->data);
    }
	return result;
}



int main(int v,char** ch){
	Queue* q = create_queue(10);
	OprResult* res = push(q,1);
	res = push(q,2);
	res = push(q,3);
	res = push(q,4);
	assert(length(q)==4);
	res = pop(q);
	assert(length(q)==3);
    assert(res->data==4);
	res = pop(q);
	assert(length(q)==2);
    assert(res->data==3);

}