#include <stdio.h>
int fun1(int a,int b){
    int min=(b>a)?a:b;
    for (int i = min; i >=1; --i) {
        if(a%i==0&&b%i==0)return i;
    }return 0;
}
int fun2(int a,int b){
    int max=(b<a)?a:b;
    for (int i = max; i <= a*b; ++i) {
        if(i%a==0&&i%b==0)return i;
    }return 0;
}
int main() {
    int a,b,num1,num2;
    scanf("%d,%d",&a,&b);
    num1= fun1(a,b);
    num2= fun2(a,b);
    printf("最大公约数：%d\n",num1);
    printf("最小公倍数：%d\n",num2);
}//
// Created by Lenovo on 2025/12/1.
//
