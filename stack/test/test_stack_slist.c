#include<assert.h>

#include "../../slist/slist.h"
#include "../stack.h"

int main(int var,char **charv){
	Slist slist = create_stack();	
	Slist *list = &slist;
	assert(length(list)==0);
	OprResult *res = push(list,10);
	assert(length(list)==1);
	assert(peek(list)->data==10);
	res = push(list,20);
	assert(length(list)==2);
	assert(peek(list)->data==20);
	res = push(list,30);
	assert(length(list)==3);
	assert(peek(list)->data==30);
	res = pop(list);
	assert(length(list)==2);
	assert(peek(list)->data==20);
	res = pop(list);
	assert(length(list)==1);
	assert(peek(list)->data==10);
	res = pop(list);
	assert(length(list)==0);
	assert(res->status == SLIST_OK);
	assert(res->data == 10);
	assert(peek(list)->status==SLIST_FAIL);
	res = pop(list);
	assert(res->status == SLIST_FAIL);
	return 1;
}