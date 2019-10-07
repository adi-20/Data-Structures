
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bst.h"

// An intermediate result while adding node
typedef struct node_res NodeRes;
struct node_res{
	Node* node;
	int status;
};

BST* create_bst(){
	// BST b = {NULL,0};
	BST* bst = (BST*) malloc(sizeof(bst));
	bst->root = NULL;
	bst->length = 0;
	return bst;
}

uint32_t length(BST* bst){
	return bst->length;
}

OprResult* create_result(DATA_TYPE_USED data,int32_t status){
	OprResult * res = (OprResult*) malloc(sizeof(OprResult));
	res->data = data;
	res->status = status;
	return res;
}

Node* create_node(DATA_TYPE_USED data,Node* left,Node* right){
	Node* node = (Node*) malloc(sizeof(Node));
	node->left = left;
	node->data = data;
	node->right = right;
	return node;
}
static NodeRes add_node(Node* node,DATA_TYPE_USED data){
	NodeRes returnNode={NULL,STATUS_FAIL};
	if(node==NULL){
		returnNode.node =  create_node(data,NULL,NULL);
		returnNode.status = STATUS_OK;
	}else{
		if(data > node->data){
			returnNode = add_node(node->right,data);
			node->right = returnNode.node;
			
		}else if(data < node->data){
			returnNode = add_node(node->left,data);
			node->left = returnNode.node;
		}else{
			assert(node->data==data);
			assert(returnNode.status == STATUS_FAIL);
		}
		returnNode.node = node;
	}
	return returnNode;
}

OprResult* add(BST* bst,DATA_TYPE_USED data){
	OprResult* res = create_result(data,STATUS_FAIL);
	NodeRes nodeRes = add_node(bst->root,data);
	bst->root = nodeRes.node;
	res->status = nodeRes.status;
	if(res->status == STATUS_OK){
		bst->length++;
	}
	res->data = data;
	return res;
}

OprResult* search_ele(BST* bst,DATA_TYPE_USED data){
	Node* node = bst->root;
	OprResult* res = create_result(data,STATUS_FAIL);
	while(node!=NULL){
		if(node->data == data){
			res->data = node->data;
			res->status = STATUS_OK;
			break;
		}else if(data>node->data){
			node = node->right;
		}else{
			node = node->left;
		}
	}
	return res;
}


static Node* find_least(Node* node,int remPrntLnk){
	if(node!=NULL){
		Node* prev = NULL;
		while(node->left!=NULL){
			prev = node;
			node = node->left;
		}
		if(prev!=NULL && remPrntLnk ==1){
			prev->left = NULL;
		}
	}
	return node;
}

OprResult* delete(BST* bst,DATA_TYPE_USED data){
	Node* node = bst->root;
	Node* prntNde = NULL;
	OprResult* res = create_result(data,STATUS_FAIL);
	while(node!=NULL){
		if(node->data == data){
			res->data = node->data;
			if(node->right==NULL){
				if(prntNde->left==node){
					prntNde->left = node->left;
				}else{
					prntNde->right = node->left;
				}
				free(node);
			}else if(node->left==NULL){
				if(prntNde->left==node){
					prntNde->left = node->right;
				}else{
					prntNde->right = node->right;
				}
				free(node);
			}else{
				Node* tmp = find_least(node->right,1);
				node->data = tmp->data;
				free(tmp);
			}
			res->status = STATUS_OK;
			bst->length--;
			break;
		}else if(data>node->data){
			prntNde = node;
			node = node->right;
		}else{
			prntNde = node;
			node = node->left;
		}

	}
	return res;
}
static void print_in_order(Node* node){
	if(node!=NULL){
		print_in_order(node->left);
		printf(" %d ",node->data);
		print_in_order(node->right);
	}
}
static void print_pre_order(Node* node){
	if(node!=NULL){
		printf(" %d ",node->data);
		print_pre_order(node->left);
		print_pre_order(node->right);
	}
}
static void print_post_order(Node* node){
	if(node!=NULL){
		print_post_order(node->left);
		print_post_order(node->right);
		printf(" %d ",node->data);
	}
}
static void print_level_order(Node* node){
	
}
void in_order(BST* bst){
	print_in_order(bst->root);
	printf("\n");
}

void pre_order(BST* bst){
	print_pre_order(bst->root);
	printf("\n");
}
void post_order(BST* bst){
	print_post_order(bst->root);
	printf("\n");
}
void level_order(BST* bst){
	print_level_order(bst->root);
	printf("\n");
}