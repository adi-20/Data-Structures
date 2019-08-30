#include "../slist.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
// To add c file from command line is prefered -- need to check stackoverflow?
// #include "slist.c"
void test_create(){
	//creating list of empty 
	Slist slist = new_list();
	Slist *list = &slist;
	assert (length(list) == 0);
	assert (lookup(list ,20) == -1);
}

void test_add_head(){
	Slist slist = new_list();
	Slist *list = &slist;

	// adding first element to list
	list = add_head(list,20);
	assert (length(list) == 1);
	assert (lookup(list ,20) == 0);

	// adding 2nd element to list
	list = add_head(list,10);
	assert (length(list) == 2);
	assert (lookup(list ,20) == 1);
	assert (lookup(list,10) == 0);

}

void test_add_tail(){
	Slist slist = new_list();
	Slist *list = &slist;
	list = add_head(list,20);
	list = add_head(list,10);

	// Adding to tail testing
	list = add_tail(list,30);
	assert (length(list) == 3);
	assert (lookup(list ,20) == 1);
	assert (lookup(list ,30) == 2);

}
void test_delete_tail(){
	Slist slist = new_list();
	Slist *list = &slist;
	list = add_head(list,20);
	list = add_head(list,10);
	list = add_tail(list,30);

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
	
	
}

void test_delete_head(){
	Slist slist = new_list();
	Slist *list = &slist;
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
}

void test_min_max(){
	Slist slist = new_list();
	Slist *list = &slist;
	// Max and Min Slist test case
	assert(max_list(list)==-1);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	list->SLIST_STATUS=SLIST_OK; // Updating SLIST_STATUS value so that value	
	assert(list->SLIST_STATUS==SLIST_OK);
	assert(min_list(list)==-1);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	for (int i=1;i<6;i++){
		list = add_head(list,i*10);
		assert(length(list)==i);
	}
	assert(length(list)==5);
	assert(max_list(list)==50);
	assert(min_list(list)==10);
	assert(list->SLIST_STATUS==SLIST_OK);
	list = delete_head(list);
	assert(max_list(list)==40);
	assert(min_list(list)==10);
	list = delete_tail(list);
	assert(max_list(list)==40);
	assert(min_list(list)==20);
	assert(list->SLIST_STATUS==SLIST_OK);
	assert(list->length == 3);
	int len = list->length;
	for(int i=1;i<=len;i++){
		list = delete_tail(list);
	}
	assert(list->length==0);
	assert(list->head == NULL);
	assert(list->tail == NULL);
}

void test_add_after(){
	Slist slist = new_list();
	Slist *list = &slist;

	assert(list->length==0);
	assert(list->head == NULL);
	assert(list->tail == NULL);
	for (int i=1;i<6;i++){
		list = add_head(list,i*10);
		assert(length(list)==i);
	}
	assert(list->length==5);
	int pos = lookup(list,30);
	assert(lookup(list,20)==(pos+1));

	assert(lookup(list,10)==(list->length-1));
	list = add_after(list,70,30);

	assert(lookup(list,10)==(list->length-1));
	assert(lookup(list,30)==pos);
	assert(lookup(list,70)==(pos+1));
	assert(lookup(list,20)==(pos+2));
	list = add_after(list,100,10);
	assert(lookup(list,100)==list->length-1);
}

void test_del_data(){
	Slist slist = new_list();
	Slist *list = &slist;
	for(int i=1;i<10;i++){
		list = add_head(list,i*10);
	}

	//Delete element doens't exist
	list = delete_node(list,100);
	assert(list->SLIST_STATUS == SLIST_FAIL);
	list->SLIST_STATUS  = SLIST_OK;

	//Delete element which is in mid
	assert(lookup(list,20)== list->length-2);
	assert(lookup(list,30)== list->length-3);
	list = delete_node(list,20);
	assert(list->SLIST_STATUS == SLIST_OK);
	assert(lookup(list,20)==-1);
	assert(lookup(list,30)== list->length-2);

	// delete tail
	assert(lookup(list,10)== list->length-1);
	list = delete_node(list,10);
	assert(list->SLIST_STATUS == SLIST_OK);
	assert(lookup(list,10)==-1);

	// Delete Head
	assert(lookup(list,90)==0);
	list = delete_node(list,90);
	assert(list->SLIST_STATUS == SLIST_OK);
	assert(lookup(list,90)==-1);
}

void test_rev(){
	//Write a method to reverse the elements in the same list.
	Slist slist = new_list();
	Slist *list = &slist;
	for(int i=1;i<10;i++){
		list = add_head(list,i*10);
	}
	assert(lookup(list,10)==list->length-1);
	assert(lookup(list,90)==0);
	list = reverse_list(list);
}

void test_slist(){
	test_create();
	test_add_head();
	test_add_tail();
	test_delete_head();
	test_delete_tail();
	test_min_max();
	test_add_after();
	test_del_data();
	test_rev();
}

int main(int arc,char **var){
	test_slist();
	return 1;
}


