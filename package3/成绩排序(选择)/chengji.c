#include <stdio.h>
#define N 10
int main( )
{
    int grade[N],num[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d",&grade[i]);
        num[i]=i+1;
    }
    int temp,temp1,s;
    for (int i = 0; i < N; i++) {
        s=i;
        for (int j = i; j < N; j++) {
            if(grade[s]<grade[j]){
                s=j;
            }
        }
        if(s!=i){
            temp=grade[i];
            temp1=num[i];
            grade[i]=grade[s];
            num[i]=num[s];
            grade[s]=temp;
            num[s]=temp1;
        }
    }
    printf("%d\n",num[0]);
    for (int i = 1; i < N; ++i) {
        if(grade[i]==grade[0]){
            printf("%d\n",num[i]);
        } else return 0;
    }
}//
// Created by Lenovo on 2025/11/27.
//
