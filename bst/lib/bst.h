#ifndef _INCLUDED_BSD_
#define _INCLUDED_BSD_
/*

1. Design a BST class with methods to add element, search element, number of elements and
   delete requested element
2. Add methods to in-order, pre-order, post-order and level-order traversals
3. Add method to find the height of binary search tree
4. Add method to count the number of terminal nodes in BST
5. Add methods to find max and min element in BST
6. Add method to display elements in ascending order
7. Add method to display elements in descending order

*/
#include <stdint.h>
#include "../../comm.h"

#define NODE_DATA_TYPE_USED int

typedef struct __node__ Node;
typedef struct __bst__ BST;

struct __node__{
	Node* left;
	NODE_DATA_TYPE_USED data;
	Node* right;
	int32_t status;
};

struct __bst__{
	Node* root;
	uint32_t length;
};

// Defining methods for double linked list
BST* create_bst();
uint32_t length_bst(BST* list);
OprResult* search_ele_bst(BST* list,NODE_DATA_TYPE_USED data);
OprResult* add_bst(BST* list,NODE_DATA_TYPE_USED data);
OprResult* delete_bst(BST* list,NODE_DATA_TYPE_USED data);
void in_order(BST* bst);
void pre_order(BST* bst);
void post_order(BST* bst);
void level_order(BST* bst);
int height_bst(BST* bst);
OprResult* max_bst(BST* bst);
OprResult* min_bst(BST* bst);

#endif
