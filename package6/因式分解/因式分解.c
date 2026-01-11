#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
void find_yin(int arr[N] ,int num);
int main( ){
    int num,arr[N];
    for(int i=0;i<N;i++) {
        arr[i]=1;
    }
    scanf("%d",&num);
    find_yin(arr,num);
    /*for(int i=0;i<N;i++) {
        printf("%d\n",arr[i]);
    }*/
    int sum=1,has_print[1000]={0};
    for(int i=0;i<N;i++) {
        if(has_print[arr[i]]>=1) {
            continue;
        }
        sum*=arr[i];
        has_print[arr[i]]++;
    }
    printf("%d\n",sum);
}
void find_yin(int arr[N] ,int num) {
    static int k=0;
    if(num==2) return;
    if (num%2==0) {
        arr[k++]=2;
        find_yin(arr,num/2);
    }else {
        int flag=0;
        for (int i=2;i<(num+1)/2;i++) {
            if (num%i==0) {
                flag=1;
                arr[k++]=i;
                find_yin(arr,num/i);
                return;
            }
        }
        if (flag==0) {
            arr[k++]=num;
        }
    }
}