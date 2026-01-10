#include <stdio.h>
#include "string.h"
#define N 20
int main(){
    int flag=0,k=0;
    char s[N],t[N],u[N];
    gets(s);
    gets(t);
    for (int i = 0; i < strlen(s); ++i) {
        for (int j = 0; j < strlen(t); ++j) {
            if(s[i]==t[j]){
                flag=1;
            }
        }
        if(flag==0){
            u[k]=s[i];
            k++;
        }
        flag=0;
    }
    puts(u);
}  //
// Created by Lenovo on 2025/11/17.
//
