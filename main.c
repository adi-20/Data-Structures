#include "slist.h"
#include <assert.h>
// To add c file from command line is prefered -- need to check stackoverflow?
#include "slist.c"

void main(char *var){
	Slist slist = new_list();
	Slist *list = &slist;
	assert (length(list) == 0);
	assert (lookup(list ,20) == -1);

	list = add_head(list,20);
	assert (length(list) == 1);
	assert (lookup(list ,20) == 0);

	list = add_head(list,10);
	assert (length(list) == 2);
	assert (lookup(list ,20) == 1);

	assert (lookup(list,30) == -1);

	// list = add_head(list,30);
	// assert (length(list) == 2);
	// assert (lookup(list ,20) == 1);
	
}


