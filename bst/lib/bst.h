#ifndef _INCLUDED_BSD_
#define _INCLUDED_BSD_

#include <stdint.h>
#include "../../comm.h"

typedef struct __node__ Node;
typedef struct __bst__ BST;

struct __node__{
	Node* left;
	DATA_TYPE_USED data;
	Node* right;
	int32_t status;
};

struct __bst__{
	Node* root;
	uint32_t length;
};

// Defining methods for double linked list
BST* create_bst();
uint32_t length(BST* list);
OprResult* search_ele(BST* list,DATA_TYPE_USED data);
OprResult* add(BST* list,DATA_TYPE_USED data);
OprResult* delete(BST* list,DATA_TYPE_USED data);
void in_order(BST* bst);
void pre_order(BST* bst);
void post_order(BST* bst);
void level_order(BST* bst);


#endif
