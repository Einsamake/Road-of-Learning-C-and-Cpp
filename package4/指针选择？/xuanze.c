#include <stdio.h>
int main() {
    int n[10];
    for(int i=0;i<10;i++) {
        scanf("%d",&n[i]);
    }
    int *p,*q=n,*min;
    for(;q-n<9;q++) {
        min=q;
        for( p=q+1;p-n<10;p++) {
            if(*p<*min) {
                min=p;
            }
        }
        if(min!=q) {
            int temp=*q;
            *q=*min;
            *min=temp;
        }
    }
    printf("%d",n[0]);
    for (int i=1;i<10;i++) {
        printf(",%d",n[i]);
    }printf("\n");

}




//
// Created by Lenovo on 2025/12/9.
//