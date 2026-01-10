#include <stdio.h>
int count(int,int);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", count(n, n-1));
    return 0;
}
int count(int n,int m){
    if(n<1||m<1)return 0;
    else if(n==1||m==1)return 1;
    else if(m>n)return count(n,n);
    else if(m==n)return count(n,m-1)+1;
    else return count(n-m,m)+ count(n,m-1);

}//
// Created by Lenovo on 2025/11/25.
//
