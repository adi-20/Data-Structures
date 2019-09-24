/*
Q) Check balancing of symbols ( like ‘{‘, ‘(‘, ‘[‘ ) and their order using stack.

To Compile : gcc -Wall  -D DATA_TYPE_USED=char ../slist/slist.c -o test1
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../slist/slist.h"
#include "../stack/stack.h"

int remove_till_close(Stack* stck,char ele){
    int flag = 0;
    OprResult* res =pop(stck);
    if(res->status == STATUS_OK && res->data == ele){
        flag = 1;
    }
    return flag;
}

int validate_exp(char ch[]){
    int flag =1;
    Stack stck = create_stack();
    Stack *stack = &stck;
    for(int i=0;i<strlen(ch);i++){
        char rm=' ';
        switch(ch[i]){
            //Checking for closing...
            case '}':
                rm = '{';
                break;
            case ']':
                rm = '[';
                break;
            case ')':
                rm = '(';
                break;
            case '{':
            case '[':
            case '(':
                push(stack,ch[i]);
                break;
            // Pushing all other to the stack
                
        }
        if(rm!=' ' && remove_till_close(stack,rm)!=1){
            flag = 0;
            break;
        }
        rm = ' ';
    }

    return flag;
}

int main(int c,char** v){
    assert(validate_exp("({})")==1);
    assert(validate_exp("({)")==0);

    assert(validate_exp("(asd{asda}asd)")==1);

    assert(validate_exp("asd({asd)")==0);

    assert(validate_exp("{{}}")==1);

    assert(validate_exp("({)}")==0);
}