#ifndef _INCLUDED_DLIST_
#define _INCLUDED_DLIST_

#define STATUS_OK 1
#define STATUS_FAIL 0

#include <stdint.h>
#include "../../comm.h"

typedef struct __node__ Node;
typedef struct __dlist__ Dlist;

struct __node__{
	Node* prev;
	DATA_TYPE_USED data;
	Node* next;
};

struct __dlist__{
	Node* head;
	Node* tail;
	uint32_t length;
};

// Defining methods for double linked list
Dlist* create_list();
uint32_t length(Dlist* list);
OprResult* search_ele(Dlist* list,DATA_TYPE_USED data);
OprResult* add_head(Dlist* list,DATA_TYPE_USED data);
OprResult* add_tail(Dlist* list,DATA_TYPE_USED data);
OprResult* add_ele_before(Dlist* list,DATA_TYPE_USED data,DATA_TYPE_USED before);
OprResult* add_ele_after(Dlist* list,DATA_TYPE_USED data,DATA_TYPE_USED after);
OprResult* delete_head(Dlist* list);
OprResult* delete_tail(Dlist* list);
OprResult* delete_ele_before(Dlist*list,DATA_TYPE_USED data);


#endif
