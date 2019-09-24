#ifndef _NS_STACK_
#define _NS_STACK_
#include <stdint.h>
#include "../slist/slist.h"
#include "../comm.h"

#define STATUS_OK 1
#define STATUS_FAIL 0

typedef Slist Stack;

Stack create_stack();
OprResult* push(Stack* list,DATA_TYPE_USED data);
OprResult* pop(Stack* list);
OprResult* peek(Stack *list);
#endif