#ifndef _NS_STACK_
#define _NS_STACK_
#include <stdint.h>
#include "../slist/slist.h"
#define STATUS_OK 1
#define STATUS_FAIL 0

// typedef struct _status_result_ OprResult;
// typedef struct Slist Stack;

struct _status_result_{
	int32_t status;
	int32_t element;	
};



Slist create_stack();
OprResult* push(Slist* list,int32_t data);
OprResult* pop(Slist* list);
OprResult* peek(Slist *list);
#endif