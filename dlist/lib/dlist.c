#include <stdlib.h>
#include <assert.h>
#include "dlist.h"


// Defining methods for double linked list
Dlist* create_list(){
	Dlist* list = (Dlist*) malloc(sizeof(Dlist));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

Node* create_node(int32_t data,Node* prev, Node* next){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->prev = prev;
	node->next = next;
	return node;
}
OprResult* create_result(int32_t data, uint32_t status){
	OprResult* result = (OprResult*) malloc(sizeof(OprResult));
	result->data = data;
	result->STATUS = status;
	return result;
}

uint32_t length(Dlist* list){
	assert(list!=NULL);
	return list->length;
}

OprResult* search_ele(Dlist* list,int32_t data){
	assert(list!=NULL);
	int32_t pos = -1;
	Node* curr = list->head;
	while(curr!=NULL){
		pos++;
		if(curr->data == data){
			break;
		}
		curr = curr->next;
	}
	return create_result(pos,STATUS_OK);
}

OprResult* add_head(Dlist* list,int32_t data){
	assert(list!=NULL);
	Node* curr = list->head;
	Node* new_node = create_node(data,NULL,curr);
	// curr->prev = new_node; // Cannot use here if curr is null then null of prev doesn't exist, causing runtime exception.
	list->head = new_node;
	if(length(list)==0){
		list->tail = new_node;
	}else{
		curr->prev = new_node;
	}
	list->length++;
	return create_result(data,STATUS_OK);
}
OprResult* add_tail(Dlist* list,int32_t data){
	assert(list!=NULL);
	Node* curr = list->tail;
	Node* new_node = create_node(data,curr,NULL);
	list->tail = new_node;
	if(length(list)==0){
		list->head= new_node;
	}else{
		curr->next = new_node;
	}
	list->length++;
	return create_result(data,STATUS_OK);

}
OprResult* delete_head(Dlist* list);
OprResult* delete_tail(Dlist* list);
