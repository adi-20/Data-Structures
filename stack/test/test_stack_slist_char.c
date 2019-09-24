#include<assert.h>

#include "../../slist/slist.h"
#include "../stack.h"

int main(int var,char **charv){
	Slist slist = create_stack();	
	Slist *list = &slist;
	assert(length(list)==0);
	OprResult *res = push(list,'a');
	assert(length(list)==1);
	assert(peek(list)->data=='a');
	res = push(list,'b');
	assert(length(list)==2);
	assert(peek(list)->data=='b');
	res = push(list,'c');
	assert(length(list)==3);
	assert(peek(list)->data=='c');
	res = pop(list);
	assert(length(list)==2);
	assert(peek(list)->data=='b');
	res = pop(list);
	assert(length(list)==1);
	assert(peek(list)->data=='a');
	res = pop(list);
	assert(length(list)==0);
	assert(res->status == SLIST_OK);
	assert(res->data == 'a');
	assert(peek(list)->status==SLIST_FAIL);
	res = pop(list);
	assert(res->status == SLIST_FAIL);
	return 1;
}