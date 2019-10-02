
#include <stdlib.h>
#include<stdio.h>

#include "bst.h"

BST* create_bst(){
	BST* bst = (BST*) malloc(sizeof(bst));
	bst->root = NULL;
	bst->length = 0;
	return bst;
}

uint32_t length(BST* bst){
	return bst->length;
}

OprResult* create_result(DATA_TYPE_USED data,int32_t status){
	OprResult* res = (OprResult*) malloc(sizeof(OprResult));
	res->data = data;
	res->status = status;
	return res;
}

Node* create_node(DATA_TYPE_USED data,Node* prevPtr,Node* nxtPtr){
	Node* node = (Node*) malloc(sizeof(Node));
	node->prev = prevPtr;
	node->data = data;
	node->next = nxtPtr;
	return node;
}

OprResult* add(BST* list,DATA_TYPE_USED data){
	Node* pos = list->root;
	Node* new_node = create_node(data,NULL,NULL);
	OprResult* res = create_result(data,STATUS_FAIL);
	if(pos==NULL){
		printf("[!] Inside NULL VALIDATOR\n");
		list->root = new_node;
		res->status = STATUS_OK;
	
	
	}
	printf("%d,%d\n",res->status,STATUS_OK);
	return res;
}
// OprResult* search_ele(BST* list,DATA_TYPE_USED data);
// OprResult* delete(BST* list);
