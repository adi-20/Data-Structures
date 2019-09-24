#include<stdio.h>
#include<assert.h>

#include "queue.h"

OprResult* push(Queue* q,DATA_TYPE_USED data){
	return add(q,data);
}

OprResult* pop(Queue* q){
	int len = length(q);
	OprResult* res = NULL;
	for(int i =0;i<len-1;i++){
		res = delete(q);
		add(q,res->data);
	}
	res = delete(q);
	return res;
}



void main(){
	Queue* q = create_queue(10);
	OprResult* res = push(q,1);
	res = push(q,2);
	res = push(q,3);
	res = push(q,4);
	res = pop(q);

	assert(res->status==STATUS_OK);
	assert(res->data==4);

	res = pop(q);

	assert(res->status==STATUS_OK);
	assert(res->data==3);


}