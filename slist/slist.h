#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_

#define SLIST_FAIL 0
#define SLIST_OK 1

#include<stdint.h>
#include "../comm.h"

typedef struct _node Node;
typedef struct _slist Slist;

struct _node {
	DATA_TYPE_USED data;
	Node *next;
};

struct _slist {
	Node *head;
	Node *tail;
	uint32_t length;
	int32_t SLIST_STATUS;
};

/**	Public Declaration for coder     **/
Slist new_list();
uint32_t length_slist(Slist *list);
int32_t lookup(Slist * list,DATA_TYPE_USED data);
Slist* add_head(Slist *list,DATA_TYPE_USED data);
Slist* add_tail(Slist *list,DATA_TYPE_USED data);
OprResult* delete_tail(Slist *list);
OprResult* delete_head(Slist *list);
DATA_TYPE_USED max_list(Slist *list);
DATA_TYPE_USED min_list(Slist *list);
Slist* add_after(Slist* list,DATA_TYPE_USED data, DATA_TYPE_USED after_data);
OprResult* delete_node(Slist* list, DATA_TYPE_USED data);
Slist* reverse_list(Slist* list);
uint32_t list_equal(Slist* list1,Slist* list2);
Slist* union_list(Slist* list1,Slist* list2);
Slist* list_intersection(Slist* list1,Slist* list2);
Slist* add_head_nexist(Slist* list,DATA_TYPE_USED data);
Slist* add_tail_nexist(Slist* list,DATA_TYPE_USED data);
Slist* add_after_nexist(Slist* list,DATA_TYPE_USED data,DATA_TYPE_USED after);

#endif
