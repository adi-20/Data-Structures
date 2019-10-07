
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bst.h"
#include "../../Queue/queue.h"

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

uint32_t length_bst(BST* bst){
	return bst->length;
}

static OprResult* create_result(Node* data,int32_t status){
	OprResult * res = (OprResult*) malloc(sizeof(OprResult));
	res->data = data;
	res->status = status;
	return res;
}

Node* create_node(NODE_DATA_TYPE_USED data,Node* left,Node* right){
	Node* node = (Node*) malloc(sizeof(Node));
	node->left = left;
	node->data = data;
	node->right = right;
	return node;
}
static NodeRes add_node(Node* node,NODE_DATA_TYPE_USED data,OprResult* res){
	NodeRes returnNode={NULL,STATUS_FAIL};
	if(node==NULL){
		returnNode.node =  create_node(data,NULL,NULL);
		res->data = returnNode.node;
		returnNode.status = STATUS_OK;
	}else{
		if(data > node->data){
			returnNode = add_node(node->right,data,res);
			node->right = returnNode.node;
			
		}else if(data < node->data){
			returnNode = add_node(node->left,data,res);
			node->left = returnNode.node;
			// if(data==5) printf("\nHello wold-tango\n");
		}else{
			// if(data==5) printf("\nHello wold3\n");
			assert(node->data==data);
			assert(returnNode.status == STATUS_FAIL);
			assert(res!=NULL);
			assert(res->status == STATUS_FAIL);
			
		}
		returnNode.node = node;
	}
	return returnNode;
}

OprResult* add_bst(BST* bst,NODE_DATA_TYPE_USED data) {
	OprResult* res = create_result(NULL,STATUS_FAIL);
	NodeRes nodeRes = add_node(bst->root, data, res);
	bst->root = nodeRes.node;
	res->status = nodeRes.status;
	if(res->status == STATUS_OK){
		bst->length++;
	}
	// res->data = nodeRes.node;
	return res;
}

OprResult* search_ele_bst(BST* bst,NODE_DATA_TYPE_USED data){
	Node* node = bst->root;
	OprResult* res = create_result(NULL,STATUS_FAIL);
	while(node!=NULL){
		if(node->data == data){
			res->data = node;
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

OprResult* delete_bst(BST* bst,NODE_DATA_TYPE_USED data){
	Node* node = bst->root;
	Node* prntNde = NULL;
	OprResult* res = create_result(NULL,STATUS_FAIL);
	while(node!=NULL){
		if(node->data == data){
			res->data = create_node(node->data,NULL,NULL);
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
static void print_level_order(Queue* queue){
	while(queue->length!=0){
		OprResult* res = delete(queue);
		Node* node = res->data;
		printf(" %d ",node->data);
		if(node->left!=NULL){
			add(queue,node->left);
		}
		if(node->right!=NULL){
			add(queue,node->right);
		}
	}
	
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
	Queue* queue =  create_queue(bst->length);
	add(queue,bst->root);
	print_level_order(queue);
	printf("\n");
}