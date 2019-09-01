#include "../slist.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h> //Just for debugging
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
	// list = add_head(list,20);
	// list = add_head(list,10);

	// Adding to tail testing
	list = add_tail(list,30);
	assert (length(list) == 1);
	assert(lookup(list,30)==0);
	assert(lookup(list ,20) == -1);
	list = add_tail(list,20);
	assert(lookup(list ,20) == 1);
	assert(lookup(list,30)==0);
	list = add_head(list,10);
	assert(lookup(list ,20) == 2);
	assert(lookup(list,30)==1);

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

	list = add_head(list,10);
	assert(lookup(list,10)==0);
	list = reverse_list(list);
	assert(lookup(list,10)==0);

	list = add_head(list,20);
	assert(lookup(list,10)==1);
	list = reverse_list(list);
	assert(lookup(list,10)==0);
	list = reverse_list(list);
	assert(lookup(list,10)==1);


	for(int i=3;i<10;i++){
		list = add_head(list,i*10);
	}
	assert(lookup(list,10)==list->length-1);
	assert(lookup(list,90)==0);
	list = reverse_list(list);
	assert(lookup(list,10)==0);
	assert(lookup(list,90)==list->length-1);

	list = reverse_list(list);
	assert(lookup(list,10)==list->length-1);
	assert(lookup(list,90)==0);
}

void test_cmd_lists(){
	Slist slist1 = new_list();
	Slist *list1 = &slist1;

	Slist slist2 = new_list();
	Slist *list2 = &slist2;

	//Test case to check empty list
	assert(list_equal(NULL,NULL)==1);
	assert(list_equal(list1,list2)==1);

	//add 1 to 190 values into list
	for(int i=1;i<20;i++){
		list1 = add_head(list1,i*10);
		list2 = add_head(list2,i*10);
	}

	//validate if equal
	assert(list_equal(list1,list2)==1);
	
	//delete a element and check if returns 0
	list1 = delete_tail(list1);
	assert(list_equal(list1,list2)==0);

	//delete a element and check if both are same
	list2 = delete_tail(list2);
	assert(list_equal(list1,list2)==1);
	list2 = delete_head(list2);
	assert(list_equal(list1,list2)==0);
	list1 = delete_head(list1);
	assert(list_equal(list1,list2)==1);
	list1 = delete_node(list1,70);
	assert(list_equal(list1,list2)==0);
	list2 = delete_node(list2,70);
	assert(list_equal(list1,list2)==1);
	list1 = reverse_list(list1);
	assert(list_equal(list1,list2)==0);
	list2 = reverse_list(list2);
	assert(list_equal(list1,list2)==1);
}

void test_union(){
	Slist slist1 = new_list();
	Slist *list1 = &slist1;

	Slist slist2 = new_list();
	Slist *list2 = &slist2;

	Slist* u_list = union_list(list1,list2);
	assert(length(u_list)==0);
	//add 1 to 190 values into list
	for(int i=1;i<12;i++){
		list1 = add_head(list1,i*10);
	}
	for(int i=8;i<20;i++){
		list2 = add_head(list2,i*10);
	}
	u_list = union_list(list1,list2);
	assert(length(u_list)==(11+11));

}

void test_intersection(){
	Slist slist1 = new_list();
	Slist *list1 = &slist1;

	Slist slist2 = new_list();
	Slist *list2 = &slist2;

	Slist* i_list ;
	i_list = list_intersection(list1,list2);
	assert(length(i_list)==0);

	for(int i=1;i<10;i++){
		list1 = add_head(list1,i*10);
	}
	for(int i=10;i<20;i++){
		list2 = add_head(list2,i*10);
	}
	i_list = list_intersection(list1,list2);
	assert(length(i_list)==0);
	list1 = add_head(list1,100);

	i_list = list_intersection(list1,list2);
	
	assert(length(i_list)==1);

	list1 = add_tail(list1,150);
	i_list = list_intersection(list1,list2);
	
	assert(length(i_list)==2);

	delete_head(list1);
	delete_tail(list1);
	i_list = list_intersection(list1,list2);
	assert(length(i_list)==0);
}

void test_add_nexist(){
	Slist slist = new_list();
	Slist *list = &slist;

	add_head_nexist(list,10);
	assert(list->SLIST_STATUS==SLIST_OK);
	assert(lookup(list,10)==0);
	assert(length(list)==1);
	add_head_nexist(list,10);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	assert(length(list)==1);

	add_tail_nexist(list,20);
	assert(list->SLIST_STATUS==SLIST_OK);
	assert(lookup(list,20)==1);
	assert(length(list)==2);
	add_tail_nexist(list,20);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	assert(length(list)==2);

	add_tail_nexist(list,30);
	assert(list->SLIST_STATUS==SLIST_OK);
	assert(lookup(list,30)==2);
	assert(length(list)==3);
	add_head_nexist(list,30);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	assert(length(list)==3);

	add_after_nexist(list,25,20);
	assert(list->SLIST_STATUS==SLIST_OK);
	assert(lookup(list,25)==2);
	assert(length(list)==4);
	add_after_nexist(list,25,20);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	assert(length(list)==4);

	list->SLIST_STATUS=SLIST_OK;

	//changing possition trying to insert
	add_after_nexist(list,25,10);
	assert(list->SLIST_STATUS==SLIST_FAIL);
	assert(length(list)==4);

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
	test_cmd_lists();
	test_intersection();
	test_add_nexist();
}

int main(int arc,char **var){
	test_slist();	
	return 1;
}


