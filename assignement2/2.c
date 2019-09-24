/*
Evaluate postfix expression using stack. Example: postfix fix expression is 6 5 2 3 + 8 * + 3 + *
Hint: When number is seen, it is pushed onto the stack; when an operator is seen, the operator
is applied to the two numbers that are popped from the stack, and the result is pushed onto the
stack.

To Compile : gcc -Wall ../slist/slist.c ../stack/s_ll.c 2.c -o test2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    if(data2->status==STATUS_OK){
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
int main(int c,char** v){
    char ch[100];
    printf("[+] Enter Postfix Expression: ");
    // scanf("%s",ch);
    fgets(ch,sizeof ch, stdin);
    Stack stck = create_stack();
    Stack *stack = &stck;
    int from=0;
    for(int i=0;i<strlen(ch);i++){
        switch(ch[i]){
            //Checking for operation...
            case '+':
            case '-':
            case '/':
            case '*':
                if(perform_operation(stack,ch[i])!=1){
                    printf("[-] Invalid Postfix Expression!!!");
                    return 0;
                }
                break;
            // Pushing all other to the stack
            case ' ':
                push(stack,substr_int(ch,from,i));
                from = i+1;
                break;
                
        }
    }
    printf("\n[+] Successfully calculated : %d",peek(stack)->data);
    printf("\n[+] Valid Expression");
}