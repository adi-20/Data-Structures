#include<assert.h>
#include<stdio.h>

#include "queue.h"

void t_c_queu(){
	Queue* q = create_queue(10);
	assert(q->size == 10);
	assert(q->top == -1);
	assert(q->bottom == 0);
	assert(q->length == 0);
	assert(length(q) ==0);
}

void t_c_add(){
	Queue* q = create_queue(10);
	OprResult* res = add(q,5);
	assert(res->status==STATUS_OK);
	assert(res->data==5);
	assert(length(q)==1);

	res = add(q,4);
	assert(res->status==STATUS_OK);
	assert(res->data==4);
	assert(length(q)==2);

	res = add(q,3);
	assert(res->status==STATUS_OK);
	assert(res->data==3);
	assert(length(q)==3);
}


void t_c_del(){
	Queue* q = create_queue(10);
	OprResult* res = add(q,5);
	res = add(q,4);
	res = add(q,3);
	res = delete(q);
	assert(res->status==STATUS_OK);
	assert(res->data==5);
	assert(length(q)==2);

	res = delete(q);
	assert(res->status==STATUS_OK);
	assert(res->data==4);
	assert(length(q)==1);

	res = delete(q);
	assert(res->status==STATUS_OK);
	assert(res->data==3);
	assert(length(q)==0);

	res = delete(q);
	assert(res->status==STATUS_FAIL);

}


int main(int c, char **v){
	t_c_queu();
	t_c_add();
	t_c_del();

}