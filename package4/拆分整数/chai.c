#include <stdio.h>
#include <string.h>

int f(int m,int n) {
    if (m==1||n==1) {
        return 1;
    }else if (m==0||n==0) {
        return 0;
    }else if (m>n) {
        return f(m-n,n)+f(m,n-1);
    }else if (m==n) {
        return 1+f(m,n-1);
    }else if (m<n) {
        return f(m,m);
    }
}
int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",f(m,n));
}
//
// Created by Lenovo on 2025/12/19.
//