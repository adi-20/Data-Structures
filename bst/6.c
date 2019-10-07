/*
    Add method to display elements in ascending order

    compile : gcc -Wall 6.c lib/bst.c ../Queue/queue.c
*/
#include <stdio.h>
#include <assert.h>
#include "lib/bst.h"

void test_ascending(){
    BST* bst = create_bst();
	add_bst(bst,10);
	add_bst(bst,20);
	add_bst(bst,5);
	add_bst(bst,0);
	add_bst(bst,15);
	add_bst(bst,25);
	in_order(bst);

}
int main(int v, char** c){
    test_ascending();
}