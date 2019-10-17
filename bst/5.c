/*
    Add methods to find max and min element in BST

    compile : gcc -Wall 5.c lib/bst.c ../Queue/queue.c
*/
#include <stdio.h>
#include <assert.h>
#include "lib/bst.h"

void test_min_bst(){
    BST* bst = create_bst();
    OprResult* res = min_bst(bst);
    assert(res->status==STATUS_FAIL);
    assert(res->data == NULL);
	
    add_bst(bst,10);

    res = min_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 10);

	add_bst(bst,20);
	res = min_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 10);
    
    add_bst(bst,5);

    res = min_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 5);
    
	add_bst(bst,0);
	add_bst(bst,15);
	add_bst(bst,25);

    res = min_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 0);
    
    
}
void test_max_bst(){
    BST* bst = create_bst();
    OprResult* res = max_bst(bst);
    assert(res->status==STATUS_FAIL);
    assert(res->data == NULL);
	
	add_bst(bst,10);
	res = max_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 10);

    add_bst(bst,20);
	res = max_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 20);

    add_bst(bst,5);
	res = max_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 20);

    add_bst(bst,0);
	add_bst(bst,15);
	add_bst(bst,25);

    res = max_bst(bst);
    assert(res->status==STATUS_OK);
    assert(((Node*)res->data)->data == 25);

}

int main(int v,char** c){
    test_min_bst();
    test_max_bst();

    printf("[+] Successfully tested min and max of BST\n");
}