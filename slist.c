
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "slist.h"

Slist new_list(){
	Slist* s =  (Slist *) malloc(sizeof(Slist));
	s->head = NULL;
	s->tail = NULL;
	s->length = 0;
	return *s;
}
uint32_t length(Slist *list){
	return list->length;
}

int32_t lookup(Slist* list,int32_t data){
	assert(list != NULL);
	int32_t count = -1;
	if(list->head != NULL){
		count = 0;
		Node* tmp = list->head;
		while(tmp!=NULL){
			if(tmp->data == data)
				break;
			count++;
			tmp = tmp->next;
		}
		// if(status){
		// 	assert(list->length==3);
		// 	assert(count==list->length);
		// }
		if(count == list->length){
			count = -1;
		}
	}
	return count;
}

Slist* add_head(Slist *list,int32_t data){
	 assert(list!=NULL);
	// Create Node
	Node * node = (Node *) malloc(sizeof(Node));
	/*
	 // Donot initialize using {} has pointer issues need to check in Stackoverflow
	 // Node snode = {};
	 // Node *node  = &snode;
	*/
	node->data = data;
	node->next = list->head;
	list->head = node;
	if(list->tail == NULL)
		list->tail = node;
	list->length++;
	return list;
}

Slist* add_tail(Slist *list,int32_t data){
	assert(list!=NULL);
	//Create node
	Node* node = (Node *) malloc(sizeof(Node));
	node->data = data;
	list->tail->next = node; //Point last node to the new node
	if(list->head==NULL)
		list->head = node;
	list->tail = node;
	list->length++;
	return list;
}

Slist* delete_tail(Slist *list){
	assert(list!=NULL);
	assert(list->head->data==10);
	assert(list->tail->data==30);
	Node* tmp = list->head;
	Node* lstNode = list->tail;
	while(tmp->next!= lstNode){
		tmp = tmp->next;
	}
	assert(list->head->data==10);
	// assert(tmp->next->data == list->tail->data);
	tmp->next = NULL;
	list->tail = tmp;
	list->length--;
	free(lstNode);
	return list;
}

Slist* delete_head(Slist *list){
	assert(list!=NULL);
	Node* tmp = list->head;
	// if(list->)
}


