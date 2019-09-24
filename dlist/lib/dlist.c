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

Node* create_node(DATA_TYPE_USED data,Node* prev, Node* next){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->prev = prev;
	node->next = next;
	return node;
}
OprResult* create_result(DATA_TYPE_USED data, uint32_t status){
	OprResult* result = (OprResult*) malloc(sizeof(OprResult));
	result->data = data;
	result->status = status;
	return result;
}

uint32_t length(Dlist* list){
	assert(list!=NULL);
	return list->length;
}

OprResult* search_ele(Dlist* list,DATA_TYPE_USED data){
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

OprResult* add_head(Dlist* list,DATA_TYPE_USED data){
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
OprResult* add_tail(Dlist* list,DATA_TYPE_USED data){
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
// ----------------------Need To work----------------------
OprResult* add_ele_before(Dlist* list,DATA_TYPE_USED data,DATA_TYPE_USED before){
	assert(list!=NULL);
	Node* curr = list->tail;
	for(Node* curr = list->tail;curr!=NULL;curr=curr->prev){
		if(curr->data == before){
			Node* new_node = create_node(data,curr->prev,curr);
			if(curr==list->head){
				list->head = new_node;
			}else{
				curr->prev->next = new_node;
			}
			curr->prev = new_node;
			list->length++;
			return create_result(data,STATUS_OK);
		}
	}
	// if element is not found
	return create_result((-1),STATUS_FAIL);
}

OprResult* add_ele_after(Dlist* list,DATA_TYPE_USED data,DATA_TYPE_USED after){
	assert(list!=NULL);
	Node* curr = list->head;
	for(Node* curr = list->head;curr!=NULL;curr=curr->next){
		if(curr->data == after){
			Node* new_node = create_node(data,curr,curr->next);
			if(curr==list->tail){
				list->tail = new_node;
			}else{
				curr->next->prev = new_node;
			}
			curr->next = new_node;
			list->length++;
			return create_result(data,STATUS_OK);
		}
	}
	// if element is not found
	return create_result(-1,STATUS_FAIL);
}

OprResult* delete_head(Dlist* list){
	assert(list!=NULL);
	Node* curr = list->head;
	OprResult* result;
	if(curr!=NULL){
		if(length(list)==1){
			list->head = NULL;
			list->tail = NULL;
		}else{
			list->head = curr->next;
			curr->next->prev = NULL;
		}
		result = create_result(curr->data,STATUS_OK);
		free(curr);
		list->length--;
	}else{
		result = create_result(-1,STATUS_FAIL);
	}
	return result;
}
OprResult* delete_tail(Dlist* list){
	assert(list!=NULL);
	Node* curr = list->tail;
	OprResult* result;
	if(curr!=NULL){
		if(length(list)==1){
			list->head = NULL;
			list->tail = NULL;
		}else{
			list->tail = curr->prev;
			curr->prev->next = NULL;
		}
		result = create_result(curr->data,STATUS_OK);
		free(curr);
		list->length--;
	}else{
		result = create_result(-1,STATUS_FAIL);
	}
	return result;
}

OprResult* delete_ele_before(Dlist*list,DATA_TYPE_USED data){
	assert(list!=NULL);
	OprResult* returnVal = create_result(-1,STATUS_FAIL);
	for(Node* curr=list->tail;curr!=NULL;curr=curr->prev){
		if(curr->data==data){
			if(curr->prev!=NULL){
				Node* free_node = curr->prev;
				curr->prev = free_node->prev;
				returnVal->data = free_node->data;
				returnVal->status = STATUS_OK;
				free(free_node);
				list->length--;
				break;
			}
		}
	}
	return returnVal;
}
