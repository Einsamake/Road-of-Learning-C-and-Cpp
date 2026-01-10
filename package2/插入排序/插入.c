#include <stdio.h>
#define N 5
int main( )
{
    int grade[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d",&grade[i]);
    }
    int temp;
    for (int i = 1,j=0; i < N; ++i) {
        if(grade[i-1]<grade[i]){
            temp=grade[i];
            for (j = i-1;j>=0&&temp>grade[j] ; j--) {
                grade[j+1]=grade[j];
            }
            grade[j+1]=temp;
        }
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ",grade[i]);
    }
}//
// Created by Lenovo on 2025/11/27.
//
