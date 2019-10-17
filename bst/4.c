/*
    Add method to count the number of terminal nodes in BST

    compile : gcc -Wall 4.c lib/bst.c ../Queue/queue.c

*/
#include <stdio.h>
#include <assert.h>
#include "lib/bst.h"

int count_leaf_node(Node* node){
    if(node!=NULL){
        if(node->left==NULL && node->right==NULL){
            return 1;
        }else if(node->left !=NULL && node->right!=NULL){
            int count = count_leaf_node(node->left);
            count+=count_leaf_node(node->right);
            return count;
        }else if(node->left!=NULL){
            return count_leaf_node(node->left);
        }else {
            return count_leaf_node(node->right);
        }
    }
    else{
        return 0;
    }
}

int count_leaf_bst(BST* bst){
    return count_leaf_node(bst->root);
}

void test_leaf_nodes(){
    BST* bst = create_bst();
    assert(count_leaf_bst(bst)==0);
	add_bst(bst,10);
    assert(count_leaf_bst(bst)==1);
	add_bst(bst,20);
    assert(count_leaf_bst(bst)==1);
	add_bst(bst,5);
    assert(count_leaf_bst(bst)==2);
	add_bst(bst,0);
    assert(count_leaf_bst(bst)==2);

	add_bst(bst,7);
    assert(count_leaf_bst(bst)==3);
	add_bst(bst,15);
    assert(count_leaf_bst(bst)==3);
	add_bst(bst,25);
    assert(count_leaf_bst(bst)==4);
    
}
int main(int v,char** c){
    test_leaf_nodes();

    printf("[+] Successfully tested number of leaf elemnt in a bst\n");
}