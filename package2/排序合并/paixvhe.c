#include "stdio.h"
#include "string.h"
int main(){
    char ch1[40]={0};
    char ch2[40]={0};
    char ch3[40]={0};
    scanf("%s",ch1);
    scanf("%s",ch2);
    for (int i = 0,j=0,k=0; 1;) {
        if(ch1[i]!=0&&ch2[j]!=0){
            if(ch1[i]<=ch2[j]){
                ch3[k]=ch1[i];
                i++;
            } else{
                ch3[k]=ch2[j];
                j++;
            }
            k++;
        }
        else if(ch1[i]!=0){
            ch3[k]=ch1[i];i++;k++;
        }
        else if(ch2[j]!=0){
            ch3[k]=ch2[j];j++;k++;
        } else break;
    }
    printf("%s\n",ch3);
}//
// Created by Lenovo on 2025/11/10.
//
