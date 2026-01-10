#include <stdio.h>
#include "string.h"
#define N 100
int main() {
    char str1[N],str2[N];
    gets(str1);
    gets(str2);
    char *p=str1,*q=str2;
    int counter=0;
    for(;p-str1<strlen(str1)-1;p++) {
        if(*p==*q&&*q!='\0') {
            int flag=1;
            for (;q-str2<strlen(str2)-1&&*q!='\0';q++,p++) {
                if (*p!=*q) {
                    flag=0;
                    break;
                }
            }if (flag==1) {
                counter++;
            }
        }
    }if (counter!=0) {
        printf("%d\n",counter);
    }else printf("No\n");

}//
// Created by Lenovo on 2025/12/9.
//