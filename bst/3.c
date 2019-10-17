/*
    Add method to find the height of binary search tree

    compile : gcc -Wall 3.c lib/bst.c ../Queue/queue.c 
*/
#include <stdio.h>
#include <assert.h>
#include "lib/bst.h"

void test_height(){
    BST* bst = create_bst();
    assert(height_bst(bst)==0);
	add_bst(bst,10);
    assert(height_bst(bst)==1);
	add_bst(bst,20);
    assert(height_bst(bst)==2);
	add_bst(bst,5);
    assert(height_bst(bst)==2);
	add_bst(bst,0);
    assert(height_bst(bst)==3);
	add_bst(bst,15);
	add_bst(bst,25);
    assert(height_bst(bst)==3);
}

int main(int v,char** c){
    test_height();

    printf("[+] Successfully tested finding height of tree\n");
}