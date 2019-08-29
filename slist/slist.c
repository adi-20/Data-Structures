
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "slist.h"



Slist new_list(){
	Slist* s =  (Slist *) malloc(sizeof(Slist));
	s->head = NULL;
	s->tail = NULL;
	s->length = 0;
	s->SLIST_STATUS = SLIST_OK;
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
	Node* lstNode = list->tail;
	if(list->length!=0){
		if(list->length != 1){
			Node* tmp = list->head;
			while(tmp->next!= lstNode){
				tmp = tmp->next;
			}
			tmp->next = NULL;
			list->tail = tmp;
		}else{
			list->tail = NULL;
			list->head = NULL;
		}
		free(lstNode);
		list->length--;
		list->SLIST_STATUS = SLIST_OK;
	}else{
		
		list->SLIST_STATUS = SLIST_FAIL;
		assert(list->SLIST_STATUS==SLIST_FAIL);
	}
	return list;
}

Slist* delete_head(Slist *list){
	assert(list!=NULL);
	if(list->head!=NULL){
		Node* tmp = list->head;
		Node* h_node = list->head;
		tmp = tmp->next;
		list->head = tmp;
		if(tmp==NULL){
			list->tail = NULL;
		}
		free(h_node);
		list->length--;
		list->SLIST_STATUS = SLIST_OK;
	}else{
		list->SLIST_STATUS = SLIST_FAIL;
	}
	return list;
}

int32_t max_list(Slist *list){
	assert(list!=NULL);
	int32_t max=-1;
	if(list->head!=NULL){
		max = list->head->data;
		Node* tmp = list->head->next;
		while(tmp!=NULL){
			if(tmp->data > max){
				max = tmp->data;
			}
			tmp = tmp->next;
		}
		list->SLIST_STATUS = SLIST_OK;
	}else{
		list->SLIST_STATUS = SLIST_FAIL;
	}
	return max;
}

