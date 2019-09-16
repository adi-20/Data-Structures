#include<stdlib.h>

#include "../slist/slist.h"

Slist create_stack(){
	Slist s = new_list();
	return s;
}
OprResult* create_sresult(int32_t status){
	OprResult* res = (OprResult*) malloc(sizeof(OprResult));
	res->status = status;
	return res;
}
OprResult* push(Slist* list,int32_t data){
	add_head(list,data);
	return create_sresult(SLIST_OK);
}

OprResult* pop(Slist* list){
	return delete_head(list);
}

OprResult* peek(Slist *list){
	Node* node =list->head;
	OprResult *res = create_sresult(SLIST_FAIL);
	if(node!=NULL){
		res->status = SLIST_OK;
		res->data = node->data;
	}
	return res;
}
