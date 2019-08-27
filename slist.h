#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_

#include<stdint.h>

typedef struct _node Node;
typedef struct _slist Slist;

struct _node {
	int32_t data;
	Node *next;
};

struct _slist {
	Node *head;
	Node *tail;
	uint32_t length;
};

/**	Public Interface for coder     **/
Slist newlist();
uint32_t length(Slist *list);
uint32_t lookup(Slist * list,int32_t data);
// Slist* add_head(Slist *list,int32_t data);
// Slist* add_tail(Slist *list,int32_t data);
// Slist* delete_tail(Slist *list);
// Slist* delete_head(Slist *list);


#endif
