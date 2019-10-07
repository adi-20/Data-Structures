/*
    Suppose you have a stack S containing n elements and a queue Q that is initially empty. 
    Write function that use Q to scan S to see if it contains a certain element x, with the additional
    constraint that your algorithm must return the elements back to S in their original order. 
    You may use S, Q and a constant number of other variables.

    compile : gcc -Wall -D DATA_TYPE_USED=int ../slist/slist.c ../stack/s_ll.c ../Queue/queue.c 5.c
*/

#include<stdio.h>
#include <stdlib.h>
#include<assert.h>

#include "../comm.h"
#include "../Queue/queue.h"
#include "../stack/stack.h"

OprResult* search_elements(Stack* s,DATA_TYPE_USED data){
    Queue* q = create_queue(length_slist(s));
    OprResult* finalRes = (OprResult*) malloc(sizeof(OprResult));
    finalRes->status = STATUS_FAIL;
    OprResult* res = NULL;
    // printf("ajith%d",res->status);
    while(s->length!=0){
        res = pop(s);
        
        if(res->status==STATUS_OK && res->data == data){
            finalRes->data = res->data;
            finalRes->status = STATUS_OK;
            push(s,res->data);
            break;
        }
        add(q,res->data);
    }
    res=NULL;
    while(q->length!=0){
        for (int i =0;i<length(q)-1;i++){
            res = delete(q);
            add(q,res->data);    
        }
        res = delete(q);
        if(res->status == STATUS_OK && res->data == data){
            push(s,res->data);
        }
    }
    return finalRes;
}

int main(int c, char** v){
    Stack s = create_stack();
    Stack* stck = &s;
    push(stck,10);
    push(stck,20);
    push(stck,30);
    OprResult* res = search_elements(stck,10);
    assert(res->status==STATUS_OK);
    assert(res->data==10);
    res = peek(stck);
    assert(res->status==STATUS_OK);
    assert(res->data==10);
    res = search_elements(stck,100);
    assert(res->status==STATUS_FAIL);

}

