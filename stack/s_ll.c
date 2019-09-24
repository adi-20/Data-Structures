#include<stdlib.h>

#include "../slist/slist.h"
#include "stack.h"

Stack create_stack(){
	Stack s = new_list();
	return s;
}
OprResult* create_sresult(int32_t status){
	OprResult* res = (OprResult*) malloc(sizeof(OprResult));
	res->status = status;
	return res;
}
OprResult* push(Stack* list,DATA_TYPE_USED data){
	add_head(list,data);
	return create_sresult(SLIST_OK);
}

OprResult* pop(Stack* list){
	return delete_head(list);
}

OprResult* peek(Stack *list){
	Node* node =list->head;
	OprResult *res = create_sresult(SLIST_FAIL);
	if(node!=NULL){
		res->status = SLIST_OK;
		res->data = node->data;
	}
	return res;
}
