
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
	Node *lstNode = list->tail;
	if(list->length!=0){
		if(list->head != list->tail){
			Node* tmp = list->head;
			while(tmp->next!= lstNode){
				tmp = tmp->next;
			}
			tmp->next = NULL;
			list->tail = tmp;
		}else{
			lstNode = list->head;
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

int32_t min_list(Slist *list){
	assert(list!=NULL);
	int32_t min = -1;
	if(list->head!=NULL){
		min = list->head->data;
		Node* tmp = list->head->next;
		while(tmp!=NULL){
			if(tmp->data<min){
				min = tmp->data;
			}
			tmp = tmp->next;
		}
		list->SLIST_STATUS = SLIST_OK;
	}else{
		list->SLIST_STATUS = SLIST_FAIL;
	}
	return min;
}
Slist* add_after(Slist* list,int32_t data,int32_t after_data){
	assert(list!=NULL);
	int count = -1;
	if(list->head != NULL){
		count = 0;
		list->SLIST_STATUS = SLIST_FAIL;
		Node* tmp = list->head;
		while(tmp!=NULL){
			if(tmp->data == after_data){
				Node* node = (Node*) malloc(sizeof(Node));
				node->data = data;
				node->next = tmp->next;
				tmp->next = node;
				list->length++;
				list->SLIST_STATUS = SLIST_OK;
				break;
			}
			count++;
			tmp = tmp->next;
		}
		if(count == list->length){
			list->SLIST_STATUS=SLIST_FAIL;
			count = -1;
		}
	}
	else{
		list->SLIST_STATUS = SLIST_FAIL;
	}
	return list;
}

Slist* delete_node(Slist* list, int32_t data){
	assert(list!=NULL);
	list->SLIST_STATUS = SLIST_FAIL;
	if(list->head!= NULL){
		if(list->head != list->tail){
			Node* prev = NULL;
			Node* curr = list->head;
			while(curr!=NULL){
				if(curr->data==data){
					if(curr == list->head){
						list->head = curr->next;
					//	freeNode = curr;
					}else if(curr == list->tail){
						list->tail = prev;
						prev->next = curr->next;
					}else{
						prev->next = curr->next;
					}
					free(curr);
					list->length--;
					list->SLIST_STATUS = SLIST_OK;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			if(curr==list->tail){
				list->SLIST_STATUS = SLIST_FAIL;
			}
		}else{
			if(list->head->data==data){
				list->SLIST_STATUS = SLIST_OK;
				list->head = NULL;
				list->tail = NULL;
			}
		}
	}
	return list;
}

Slist* reverse_list(Slist* list){
	Node* tmp= list->head;
	Node* curr = tmp->next;
	int count=1;
	while(curr!=NULL){
		Node* next = curr->next;
		curr->next = tmp;
		tmp = curr;
		count++;
	}
	assert(count==list->length-1);
	return list;
}