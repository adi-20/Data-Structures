#include "slist.h"
#include <assert.h>
// To add c file from command line is prefered -- need to check stackoverflow?
#include "slist.c"

void main(char *var){
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
	assert (lookup(list,30) == -1);

	// Adding to tail testing
	list = add_tail(list,30);
	assert (length(list) == 3);
	assert (lookup(list ,20) == 1);
	assert (lookup(list ,30) == 2);
	assert (lookup(list ,50) == -1);

	// Testing delete operation
	assert(lookup(list,30)==(slist.length-1)); // check if 30 is last element using object
	assert(lookup(list,30)==(list->length-1)); //check if 30 is last element
	list = delete_tail(list);
	assert(lookup(list,30)==-1); // check if last element is deleted

	


	
}


