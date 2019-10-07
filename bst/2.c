/*
	Add methods to in-order, pre-order, post-order and level-order traversals
	
	compile : gcc -Wall 2.c lib/bst.c ../Queue/queue.c
*/
#include <stdio.h>
#include <assert.h>
#include "lib/bst.h"

void test_order(){
	BST* bst = create_bst();
	add_bst(bst,10);
	add_bst(bst,20);
	add_bst(bst,5);
	add_bst(bst,0);
	add_bst(bst,15);
	add_bst(bst,25);
	in_order(bst);
	pre_order(bst);
	post_order(bst);
	level_order(bst);

	delete_bst(bst,0);
	printf("\nAfter Deleting :0\n");
	in_order(bst);
	pre_order(bst);
	post_order(bst);
	level_order(bst);
}

int main(int v,char** c){
	test_order();

	printf("[+] All Test Complete\n");

}
