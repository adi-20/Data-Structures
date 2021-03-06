
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>//Just for debugging
#include <assert.h>

#include "slist.h"



Slist new_list(){
	Slist* s =  (Slist *) malloc(sizeof(Slist));
	s->head = NULL;
	s->tail = NULL;
	s->length = 0;
	s->SLIST_STATUS = STATUS_OK;
	return *s;
}
Node* create_node(DATA_TYPE_USED data,Node* ptr){
	Node * node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = ptr;
	return node;
}
static OprResult* create_result(int32_t status){
	OprResult* res = (OprResult*) malloc(sizeof(OprResult));
	res->status = status;
	return res;
}
uint32_t length_slist(Slist *list){
	return list->length;
}

int32_t lookup(Slist* list,DATA_TYPE_USED data){
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

Slist* add_head(Slist *list,DATA_TYPE_USED data){
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

Slist* add_tail(Slist *list,DATA_TYPE_USED data){
	assert(list!=NULL);
	//Create node
	Node* node = create_node(data,NULL);
	// Node* node = (Node *) malloc(sizeof(Node));
	// node->data = data;
	 //Point last node to the new node
	if(list->head==NULL)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	list->length++;
	return list;
}

OprResult* delete_tail(Slist *list){
	assert(list!=NULL);
	Node *lstNode = list->tail;
	OprResult* res = create_result(STATUS_FAIL);
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
		res->data= lstNode->data;
		res->status = STATUS_OK;
		free(lstNode);
		list->length--;
		list->SLIST_STATUS = STATUS_OK;
	}else{
		res->status = STATUS_FAIL;
	}
	return res;
}

OprResult* delete_head(Slist *list){
	assert(list!=NULL);
	OprResult* res = create_result(STATUS_FAIL);
	if(list->head!=NULL){
		Node* tmp = list->head;
		Node* h_node = list->head;
		tmp = tmp->next;
		list->head = tmp;
		if(tmp==NULL){
			list->tail = NULL;
		}
		res->data = h_node->data;
		res->status = STATUS_OK;
		free(h_node);
		list->length--;
	}
	return res;
}

DATA_TYPE_USED max_list(Slist *list){
	assert(list!=NULL);
	DATA_TYPE_USED max=(DATA_TYPE_USED)-1;
	if(list->head!=NULL){
		max = list->head->data;
		Node* tmp = list->head->next;
		while(tmp!=NULL){
			if(tmp->data > max){
				max = tmp->data;
			}
			tmp = tmp->next;
		}
		list->SLIST_STATUS = STATUS_OK;
	}else{
		list->SLIST_STATUS = STATUS_FAIL;
	}
	return max;
}

DATA_TYPE_USED min_list(Slist *list){
	assert(list!=NULL);
	DATA_TYPE_USED min =(DATA_TYPE_USED) -1;
	if(list->head!=NULL){
		min = list->head->data;
		Node* tmp = list->head->next;
		while(tmp!=NULL){
			if(tmp->data<min){
				min = tmp->data;
			}
			tmp = tmp->next;
		}
		list->SLIST_STATUS = STATUS_OK;
	}else{
		list->SLIST_STATUS = STATUS_FAIL;
	}
	return min;
}
Slist* add_after(Slist* list,DATA_TYPE_USED data,DATA_TYPE_USED after_data){
	assert(list!=NULL);
	int count = -1;
	if(list->head != NULL){
		count = 0;
		list->SLIST_STATUS = STATUS_FAIL;
		Node* tmp = list->head;
		while(tmp!=NULL){
			if(tmp->data == after_data){
				Node* node = create_node(data,tmp->next);
				// Node* node = (Node*) malloc(sizeof(Node));
				// node->data = data;
				// node->next = tmp->next;
				tmp->next = node;
				list->length++;
				list->SLIST_STATUS = STATUS_OK;
				break;
			}
			count++;
			tmp = tmp->next;
		}
		if(count == list->length){
			list->SLIST_STATUS=STATUS_FAIL;
			count = -1;
		}
	}
	else{
		list->SLIST_STATUS = STATUS_FAIL;
	}
	return list;
}

OprResult* delete_node(Slist* list, DATA_TYPE_USED data){
	assert(list!=NULL);
	OprResult* res = create_result(STATUS_FAIL);
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
					res->data = curr->data;
					res->status = STATUS_OK;
					free(curr);
					list->length--;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			if(curr==list->tail){
				res->status = STATUS_FAIL;
			}
		}else{
			if(list->head->data==data){
				res->status = STATUS_OK;
				list->head = NULL;
				list->tail = NULL;
			}
		}
	}
	return res;
}

Slist* reverse_list(Slist* list){
	// Node* tmp= list->head;
	// Node* curr = tmp->next;
	// int count=1;
	// while(curr!=NULL){
	// 	Node* next = curr->next;
	// 	curr->next = tmp;
	// 	tmp = curr;
	// 	count++;
	// }
	// assert(count==list->length-1);
	Node* prev = list->head;
	Node* curr = prev->next;
	prev->next = NULL;
	int count = 1;
	while(curr!=NULL){
		Node* tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
		count++;
	}

	// Swapping head and tail
	Node* tmp = list->head;
	list->head = list->tail;
	list->tail = tmp;
	assert(list->length == count); // count times while looped

	
	return list;
}

uint32_t list_equal(Slist* list1,Slist* list2){
	// Create two separate single lists. Check two list are same.
	// If the two lists have the same number of elements in the same order,
	// then they are treated as same.
	uint32_t flag = 1;
	if(list1==NULL && list2== NULL){
		flag = 1;
	}else if(length_slist(list1)==length_slist(list2)){
		Node* n1=list1->head;
		Node* n2=list2->head;
		for(int i = 0;i<list1->length;i++){
			if(n1->data != n2->data){
				flag = 0;
			}
		}
	}else{
		flag = 0;
	}
	return flag;

}

Slist* union_list(Slist* list1,Slist* list2){
	assert(list1!=NULL);
	assert(list2!=NULL);
	Slist newList = new_list();
	Slist* list = &newList;
	
	//add first list to return list
	for(Node* curr = list1->head->next;curr!=NULL;curr=curr->next){
		list=add_tail(list,curr->data);
	}

	// add second list to return list
	for(Node* curr = list2->head->next;curr!=NULL;curr=curr->next){
		list=add_tail(list,curr->data);
	}
	return list;
}

Slist* list_intersection(Slist* list1,Slist* list2){
	assert(list1!=NULL);
	assert(list2!=NULL);

	Slist slist = new_list();
	Slist *r_list = &slist;
	for(Node* curr=list1->head;curr!=NULL;curr=curr->next){
		if(lookup(list2,curr->data)!=-1){
		DATA_TYPE_USED data = curr->data;
		r_list = add_tail_nexist(r_list,data);
		}
	}

	return r_list;
}

Slist* add_head_nexist(Slist* list,DATA_TYPE_USED data){
	// Create single list such that it should always contain unique elements. 
	// Care should be taken that,if element is already present in the list, 
	// you should not add it again.
	if(lookup(list,data)==-1){
		list = add_head(list,data);
		list->SLIST_STATUS = STATUS_OK;
	}else {
		list->SLIST_STATUS = STATUS_FAIL;
	}
	return list;
}

Slist* add_tail_nexist(Slist* list,DATA_TYPE_USED data){
	// Create single list such that it should always contain unique elements. 
	// Care should be taken that,if element is already present in the list, 
	// you should not add it again.
	if(lookup(list,data)==-1){
		list = add_tail(list,data);
		list->SLIST_STATUS = STATUS_OK;
	}else {
		list->SLIST_STATUS = STATUS_FAIL;
	}
	return list;
}

Slist* add_after_nexist(Slist* list,DATA_TYPE_USED data,DATA_TYPE_USED after){
	// Create single list such that it should always contain unique elements. 
	// Care should be taken that,if element is already present in the list, 
	// you should not add it again.
	if(lookup(list,data)==-1){
		list = add_after(list,data,after);
		list->SLIST_STATUS = STATUS_OK;
	}else {
		list->SLIST_STATUS = STATUS_FAIL;
	}
	return list;
}
