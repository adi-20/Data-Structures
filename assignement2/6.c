/*

Design a queue using two stacks as instance variables, such that all queue operations execute
in amortized O(1) time.

Compile : gcc -Wall -D DATA_TYPE_USED=int ../stack/s_ll.c ../slist/slist.c 6.c
*/

#include <assert.h>
#include <stdlib.h>
#include "../stack/stack.h"

OprResult* add(Stack* stck,DATA_TYPE_USED val){
	return push(stck,val);
}

OprResult* delete(Stack* stck){
	Stack tmp_s = create_stack();	
	Stack* tmp_stck = &tmp_s;
	int32_t length = stck->length;
	for(int i = 0;i<length-1;i++){
		push(tmp_stck,pop(stck)->data);
	}
	assert(length-1==tmp_stck->length);
	OprResult* res = pop(stck);
	for(int i = 0;i<length-1;i++){
		push(stck,pop(tmp_stck)->data);
	}
	return res;
}

OprResult* search(Stack* stck,DATA_TYPE_USED value){
	Stack tmp_s = create_stack();	
	Stack* tmp_stck = &tmp_s;
	
	OprResult* result = (OprResult*) malloc(sizeof(OprResult));
	result->status = STATUS_FAIL;
	
	while(1){
		OprResult* res = pop(stck);
		if(res->status==STATUS_OK && res->data == value){
			result ->status = STATUS_OK;
			result->data = value;
			break;
		}
		push(tmp_stck,res->data);
	}
	int32_t length = tmp_stck->length;
	for(int i = 0;i<length;i++){
		push(stck,pop(tmp_stck)->data);
	}
	return result;	
}

int main(int v,char **c){
	Stack s = create_stack();
	Stack* stck = &s;
	add(stck,10);
	add(stck,20);
	add(stck,30);
	add(stck,40);
	int32_t length = stck->length;
	assert(delete(stck)->data==10);
	assert(stck->length == length-1);
	OprResult* res = search(stck,20);
	assert(res->status == STATUS_OK);
	assert(res->data == 20);
}


