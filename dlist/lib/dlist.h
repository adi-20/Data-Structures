#ifndef _INCLUDED_DLIST_
#define _INCLUDED_DLIST_

#define STATUS_OK 1
#define STATUS_FAIL 0

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

struct __result__{
	int32_t data;
	uint32_t STATUS;
};

// Defining methods for double linked list
Dlist* create_list();
uint32_t length(Dlist* list);
OprResult* search_ele(Dlist* list,int32_t data);
OprResult* add_head(Dlist* list,int32_t data);
OprResult* add_tail(Dlist* list,int32_t data);
OprResult* add_ele_before(Dlist* list,int32_t data,int32_t before);
OprResult* add_ele_after(Dlist* list,int32_t data,int32_t after);
OprResult* delete_head(Dlist* list);
OprResult* delete_tail(Dlist* list);
OprResult* delete_ele_before(Dlist*list,int32_t data);


#endif
