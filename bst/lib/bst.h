#ifndef _INCLUDED_BSD_
#define _INCLUDED_BSD_

#include <stdint.h>
#include "../../comm.h"

typedef struct __node__ Node;
typedef struct __bst__ BST;

struct __node__{
	Node* prev;
	DATA_TYPE_USED data;
	Node* next;
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
OprResult* delete(BST* list);


#endif
