/*
Evaluate postfix expression using stack. Example: postfix fix expression is 6 5 2 3 + 8 * + 3 + *
Hint: When number is seen, it is pushed onto the stack; when an operator is seen, the operator
is applied to the two numbers that are popped from the stack, and the result is pushed onto the
stack.

To Compile : gcc -Wall  ../slist/slist.c ../stack/s_ll.c 2.c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../slist/slist.h"
#include "../stack/stack.h"

int32_t substr_int(char ca[],uint32_t start,uint32_t end){
    char sub_char[end-start];
    for (int i = 0;i<end-start;i++){
        sub_char[i] = ca[start+i];
    }
    return atoi(sub_char);
}
int32_t perform_operation(Stack* stack,char opr){
    OprResult* data1 = pop(stack);
    OprResult* data2 = pop(stack);
    int flag = 0;
    // printf("\ndata1 :: %d :: %d",data1->data,data1->status);
    // printf("\ndata2 :: %d :: %d",data2->data,data2->status);
    if(data1->status==STATUS_OK && data2->status==STATUS_OK){
        switch(opr){
            case '+':
                push(stack,data1->data + data2->data);
                break;
            case '-':
                push(stack,data1->data - data2->data);
                break;
            case '/':
                push(stack,(data1->data) / (data2->data));
                break;
            case '*':
                push(stack,data1->data * data2->data);
                break;
        }
        flag = 1;
    }else{
        flag = -1;
    }
    return flag;

}
OprResult* evaluate_postfix(char ch[]){
    OprResult* res = (OprResult*) malloc(sizeof(OprResult));
    Stack stck = create_stack();
    Stack *stack = &stck;
    int test = 0;
    int from=0;
    for(int i=0;i<strlen(ch);i++){
        switch(ch[i]){
            //Checking for operation...
            case '+':
            case '-':
            case '/':
            case '*':
                test = perform_operation(stack,ch[i]);
                if(test!=1){
                    res->status = STATUS_FAIL;
                    return res;
                }
                from = i+1;
                break;
            // Pushing all other to the stack
            case ' ':
                if(from==i && ch[i]==' '){
                    
                }else{
                    push(stack,substr_int(ch,from,i));
                    from = i+1;
                }
                break;
                
        }
    }
    if(stack->length>1){
        res->status = STATUS_FAIL;
    }else{
        res->data = peek(stack)->data;
        res->status = STATUS_OK;
    }
    
    return res;
}
int main(int c,char** v){
    // printf("%d\n",evaluate_postfix("12 3 +")->status);
    OprResult* res;
    assert(evaluate_postfix("12 3 +")->data==15);
    assert(evaluate_postfix("12 3 +")->status==STATUS_OK);
    assert(evaluate_postfix("12 3 ")->status==STATUS_FAIL);
    assert(evaluate_postfix("100 3 +")->data==103);
    assert(evaluate_postfix("100 3 +")->status==STATUS_OK);
    assert(evaluate_postfix("12 3 + +")->status==STATUS_FAIL);
    res = evaluate_postfix("12 3 + 4 +");
    assert(res->status==STATUS_OK);
    assert(res->data==19);
    res = evaluate_postfix("1 1 12 3 + 1 * + 4 + *");
    assert(res->status==STATUS_OK);
    assert(res->data==20);
    res = evaluate_postfix("6 5 2 3 + 8 * + 3 + *");
    assert(res->status==STATUS_OK);
    assert(res->data==288);
}