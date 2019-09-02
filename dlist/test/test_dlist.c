
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
void test_delete_head(){
	Dlist* list = create_list();
	add_head(list,10);
	add_head(list,20);
	add_tail(list,5);

	//List has 20,10,5 <- in same order
	OprResult* result = delete_head(list);
	assert(result->data==20);
	assert(result->STATUS==STATUS_OK);
	result = delete_head(list);
	assert(result->data==10);
	assert(result->STATUS==STATUS_OK);
	result = delete_head(list);
	assert(result->data==5);
	assert(result->STATUS==STATUS_OK);
	result = delete_head(list);
	assert(result->data==-1);
	assert(result->STATUS==STATUS_FAIL);
}

void test_delete_tail(){
	Dlist* list = create_list();
	add_head(list,10);
	add_head(list,20);
	add_tail(list,5);

	//List has 20,10,5 <- in same order
	OprResult* result = delete_tail(list);
	assert(result->data==5);
	assert(result->STATUS==STATUS_OK);
	result = delete_tail(list);
	assert(result->data==10);
	assert(result->STATUS==STATUS_OK);
	result = delete_tail(list);
	assert(result->data==20);
	assert(result->STATUS==STATUS_OK);
	result = delete_tail(list);
	assert(result->data==-1);
	assert(result->STATUS==STATUS_FAIL);
}
void test_add_after(){
	Dlist* list = create_list();
	assert(add_ele_after(list,20,10)->STATUS==STATUS_FAIL);
	assert(add_head(list,10)->STATUS==STATUS_OK);
	assert(search_ele(list,10)->data==0);
	assert(add_ele_after(list,20,10)->STATUS==STATUS_OK);
	assert(search_ele(list,10)->data==0);
	assert(search_ele(list,20)->data==1);

	assert(add_ele_after(list,15,10)->STATUS==STATUS_OK);
	assert(search_ele(list,10)->data==0);
	assert(search_ele(list,20)->data==2);
	assert(search_ele(list,15)->data==1);
}

void test_add_before(){
	Dlist* list = create_list();
	assert(add_ele_before(list,20,10)->STATUS==STATUS_FAIL);
	assert(add_tail(list,10)->STATUS==STATUS_OK);
	assert(search_ele(list,10)->data==0);
	assert(add_ele_before(list,20,10)->STATUS==STATUS_OK);
	assert(search_ele(list,10)->data==1);
	assert(search_ele(list,20)->data==0);

	assert(add_ele_before(list,15,10)->STATUS==STATUS_OK);
	assert(search_ele(list,10)->data==2);
	assert(search_ele(list,20)->data==0);
	assert(search_ele(list,15)->data==1);
}

void test_delete_before(){
	Dlist* list = create_list();
	OprResult* result = delete_ele_before(list,10);
	assert(result->data == -1);
	assert(result->STATUS == STATUS_FAIL);

	//cannot delete element which is at position 0 with length 1
	add_head(list,10);
	result = delete_ele_before(list,10);
	assert(result->data == -1);
	assert(result->STATUS == STATUS_FAIL);

	//trying to delete element before position 0 with length 2
	add_head(list,20);
	result = delete_ele_before(list,20);
	assert(result->data == -1);
	assert(result->STATUS == STATUS_FAIL);

	assert(length(list)==2);
	result = delete_ele_before(list,10);
	assert(result->data == 20);
	assert(result->STATUS == STATUS_OK);
	assert(length(list)==1); // length should be decreased
	
}



int main(int arc, char** argv){
	test_create();
	test_add_head();
	test_add_tail();
	test_delete_head();
	test_delete_tail();

	test_add_after();
	test_add_before();
	test_delete_before();
}