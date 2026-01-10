#include <stdio.h>
#include "string.h"
#define N 100
int main(){
    int flag=0,k=0;
    char s[N],t[N];
    gets(s);
    for (int i = 0; i < strlen(s); ++i) {
        for (int j = 0; j < strlen(t); ++j) {
            if(s[i]==t[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            t[k]=s[i];
            k++;
        }
        flag=0;
    }
    t[k]='\0';
    puts(t);
}//
// Created by Lenovo on 2025/11/17.
//
