#include "../slist.h"
#include <assert.h>
// To add c file from command line is prefered -- need to check stackoverflow?
// #include "slist.c"
void test_slist(){
	//creating list of empty 
	Slist slist = new_list();
	Slist *list = &slist;
	assert (length(list) == 0);
	assert (lookup(list ,20) == -1);


	// adding first element to list
	list = add_head(list,20);
	assert (length(list) == 1);
	assert (lookup(list ,20) == 0);

	// adding 2nd element to list
	list = add_head(list,10);
	assert (length(list) == 2);
	assert (lookup(list ,20) == 1);
	assert (lookup(list,10) == 0);


	// Adding to tail testing
	list = add_tail(list,30);

	assert (length(list) == 3);
	assert (lookup(list ,20) == 1);
	assert (lookup(list ,30) == 2);


	// Testing delete operation
	assert(lookup(list,30)==(list->length-1)); //check if 30 is last element
	assert(list->tail->data==30);
	list = delete_tail(list);
	assert(lookup(list,30)!=(list->length-1));
	assert(lookup(list,30)==-1); // check if last element is deleted
	
	// deleting all elements from list
	int len = list->length;
	for(int i=0;i<len;i++){
		list = delete_tail(list);
	}

	//list should be empty
	assert(lookup(list,10)==-1);
	assert(length(list)==0);
	list = delete_tail(list);
	assert(list->SLIST_STATUS==SLIST_FAIL);

	list = add_head(list,10);
	list = add_head(list,20);
	list = add_head(list,30);
	assert(length(list)==3);

	assert(lookup(list,30)==0);
	assert(length(list)==3);
	list = delete_head(list);	
	assert(lookup(list,30)==-1);
	assert(length(list)==2);
	list = delete_head(list);
	assert(lookup(list,20)==-1);
	assert(length(list)==1);
	assert(list->SLIST_STATUS==SLIST_OK);
	list = delete_head(list);
	assert(lookup(list,10)==-1);
	assert(length(list)==0);
	list = delete_head(list);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	assert(length(list)==0);
	assert(max_list(list)==-1);



	assert(list->SLIST_STATUS==SLIST_FAIL);
	for (int i=1;i<4;i++){
		list = add_head(list,i*10);
		assert(length(list)==i);
	}
	assert(length(list)==3);
	assert(max_list(list)==30);
	assert(list->SLIST_STATUS==SLIST_OK);


}

int main(int arc,char **var){
	test_slist();
	return 1;
}


