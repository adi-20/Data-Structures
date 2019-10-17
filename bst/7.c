/*
    Add method to display elements in descending order

    compile:   gcc -Wall 6.c lib/bst.c ../Queue/queue.c
*/
#include <stdio.h>
#include <assert.h>
#include "lib/bst.h"

void print_decending(Node* node){
	if(node!=NULL){
		print_decending(node->right);
		printf(" %d ",node->data);
        print_decending(node->left);
	}
}

void decending(BST* bst){
    print_decending(bst->root);
    printf("\n");
}


void test_decending(){
    BST* bst = create_bst();
	add_bst(bst,10);
	add_bst(bst,20);
	add_bst(bst,5);
	add_bst(bst,0);
	add_bst(bst,15);
	add_bst(bst,25);
	decending(bst);

}

int main(int v, char** c){
    test_decending();
}