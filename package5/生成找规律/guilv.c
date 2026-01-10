#include <stdio.h>
#include <stdlib.h>
int search(int n,int k);
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int result=(search(n,k)<0)?0:1;
    printf("%d\n",result);
}
int search(int n,int k) {
    if(n==1)return -1;
    else if(k%2==1)return search(n-1,(k+1)/2);
    else return -search(n-1,k/2);

}//
// Created by Lenovo on 2025/12/22.
//