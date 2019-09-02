
#include <stdlib.h>
#include <assert.h>

//Including double linked list header
#include "../lib/dlist.h"


void test_create(){
	Dlist* list = create_list();
	assert(list->head == NULL);
	assert(list->tail == NULL);
	assert(length(list) == 0);
	OprResult* result = search_ele(list,10);
	assert(result->STATUS==STATUS_OK);
	assert(result->data==-1);
}

void test_add_head(){
	Dlist* list = create_list();
	assert(add_head(list,10)->STATUS==STATUS_OK);
	assert(length(list)==1);
	assert(search_ele(list,10)->data==0);

	assert(add_head(list,20)->STATUS==STATUS_OK);
	assert(length(list)==2);
	assert(search_ele(list,10)->data==1);
	assert(search_ele(list,20)->data==0);
}

void test_add_tail(){
	Dlist* list = create_list();
	assert(add_tail(list,10)->STATUS==STATUS_OK);
	assert(length(list)==1);
	assert(search_ele(list,10)->data==0);

	assert(add_tail(list,20)->STATUS==STATUS_OK);
	assert(length(list)==2);
	assert(search_ele(list,10)->data==0);
	assert(search_ele(list,20)->data==1);

	//testing if adding head
	assert(add_head(list,30)->STATUS==STATUS_OK);
	assert(length(list)==3);
	assert(search_ele(list,10)->data==1);
	assert(search_ele(list,20)->data==2);
	assert(search_ele(list,30)->data==0);
}

int main(int arc, char** argv){
	test_create();
	test_add_head();
	test_add_tail();
}