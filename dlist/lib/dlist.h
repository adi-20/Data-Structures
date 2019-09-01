#ifndef _INCLUDED_DLIST_
#define _INCLUDED_DLIST_

#define DLIST_OK 1
#define DLIST_FAIL 0

#include <stdint.h>

typedef struct __node__ Node;
typedef struct __dlist__ Dlist;
typedef struct __result__ OprResult;

struct __node__{
	Node* prev;
	int32_t data;
	Node* next;
};

struct __dlist__{
	Node* head;
	Node* tail;
	uint32_t length;
};

struc __result__{
	int32_t data;
	uint32_t STATUS;
}

// Defining methods for double linked list
Dlist* create_list();
uint32_t length(Dlist* list);
OprResult* search_ele(Dlist* list, data);
OprResult* add_head(Dlist* list,data);
OprResult* add_tail(Dlist* list,data);
OprResult* delete_head(Dlist* list);
OprResult* delete_tail(Dlist* list);



#endif
