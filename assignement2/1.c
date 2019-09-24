/*
Q) Check balancing of symbols ( like ‘{‘, ‘(‘, ‘[‘ ) and their order using stack.

To Compile : gcc -Wall  -D DATA_TYPE_USED=char ../slist/slist.c -o test1
*/
#include <stdio.h>
#include <string.h>

#include "../slist/slist.h"
#include "../stack/stack.h"

int remove_till_close(Stack* stck,char ele){
    int flag = 0;
    while(stck->length >0){
        OprResult* res =pop(stck);
        switch(res->data){
            case '{':
            case '[':
            case '(':
                if(ele == res->data){
                    flag = 1;
                    break;
                }else{
                    flag = -1;
                }
        }
    }
    return flag;
}

int main(int c,char** v){
    char ch[30];
    printf("[+] Enter expression: ");
    scanf("%s",ch);
    Stack stck = create_stack();
    Stack *stack = &stck;
    for(int i=0;i<strlen(ch);i++){
        char rm;
        switch(ch[i]){
            //Checking for closing...
            case '}':
                rm = '{';
            case ']':
                rm = '[';
            case ')':
                rm = '(';
                if(remove_till_close(stack,rm)!=1){
                    printf("\n[-] Invalid Expression!!! \n");
                    return 0;
                }
                break;
            // Pushing all other to the stack
            default:
                push(stack,ch[i]);
        }
    }

    /// Poping all elements to validate for any braces remaining
    while(stack->length >0){
        OprResult* res =pop(stack);
        switch(res->data){
            case '{':
            case '[':
            case '(':
                printf("\n[-] Invalid Expression!!! \n");
                return 0;
        }
    }
    
    printf("\n[+] Valid Expression");
}