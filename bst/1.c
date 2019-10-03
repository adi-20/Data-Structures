/*
	Design a BST class with methods to add element, search element, number of elements and
	delete requested element
	compile : 
*/
#include <stdio.h>
#define DATA_TYPE_USED int
#include <assert.h>
#include "lib/bst.h"

void test_create_bst(){
	BST* bst = create_bst();
	assert(bst->length ==0);
	assert(bst->root == NULL);
	printf("%d\n",length(bst));
	assert(length(bst)==0);
}

void test_add_bst(){
	BST* bst = create_bst();
	OprResult res = add(bst,10);
	
	printf("%d,%d\n",res.status,STATUS_OK);
	assert(res.status == STATUS_OK);
	assert(res.data == 10);
	assert(bst->root->data==10);
	assert(bst->length==1);
	res = add(bst,10);
	assert(res.status == STATUS_OK);
	assert(res.data == 10);
	assert(bst->root->data==10);
	assert(bst->length==2);
	
}
int main(int v,char** c){
	test_create_bst();
	test_add_bst();

	printf("[+] All Test Complete\n");

}

