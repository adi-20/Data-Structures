#ifndef _NS_STACK_
#define _NS_STACK_
#include <strint.h>
#include "../slist/slist.h"
#define STATUS_OK 1
#define STATUS_FAIL 0

typedef struct _status_result_ OprResult
typedef struct Slist Stack

struct _status_result_{
	int32_t status;
	int32_t element;	
}



Stack* create_stack();
OprResult push();
OprResult pop();
OprResult peek();
#endif