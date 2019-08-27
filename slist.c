
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "slist.h"

Slist new_list(){
	Slist s =  {NULL,NULL,0};
	return s;
}
uint32_t length(Slist *list){
	return list->length;
}

int32_t lookup(Slist * list,int32_t data){
	assert(list != NULL);
	int32_t count = -1;
	if(list->head != NULL){
		count = 0;
		Node tmp = list->head;
		while(tmp!=null){
			tmp->data == data;
			count++;
		}
	}
	return count;
}


