#include<stdio.h>

int main(int v,char** c){
    int a[5] = {1,2,3,6,7};
    int *b = a;
    printf("\n%d",a[1]);
    printf("\n%d",b[2]);
    printf("\n%lu",sizeof(a));
    printf("\n%d",(int)(sizeof(a)/sizeof(int)));
    printf("\n%d",(int)(sizeof(*b)/sizeof(int)));
}