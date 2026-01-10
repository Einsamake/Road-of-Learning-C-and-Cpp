#include <stdio.h>

void sort(int arr[],int size){
    int j,tmp;
    for (int i = 1; i < size; ++i) {
        if(arr[i]<arr[i-1]){
            tmp=arr[i];
            for (j = i-1; j>=0&&arr[j]>tmp ; j--) {
                arr[j+1]=arr[j];
            }
            arr[j+1]=tmp;
        }
    }
}
int main(){
    int head,man,cost=0,flag=0;
    scanf("%d%d",&head,&man);
    int head_dia[head],man_height[man];
    for (int i = 0; i < head; ++i) {
        scanf("%d",&head_dia[i]);
    }

    for (int i = 0; i < man; ++i) {
        scanf("%d",&man_height[i]);
    }

    sort(head_dia,head);
    sort(man_height,man);
    if(man<head){
        printf("bit is doomed!\n");
        return 0;
    }
    /*for (int i = 0; i < head; ++i) {
        printf("%d  ",head_dia[i]);
    }
    printf("\n");
    for (int i = 0; i < man; ++i) {
        printf("%d  ",man_height[i]);
    }*/
    for (int i = 0; i < head; ++i) {
        for (int j = 0; j < man; ++j) {
            if(man_height[j]>=head_dia[i]){
                flag=1;
                cost+=man_height[j];
                man_height[j]=0;
                break;
            }
        }
        if(flag==0){
            printf("bit is doomed!\n");
            return 0;
        }
        flag=0;
    }
    printf("%d\n",cost);
    return 0;
}

//
// Created by Lenovo on 2025/11/18.
//
