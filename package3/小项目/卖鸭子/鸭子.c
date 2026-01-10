#include <stdio.h>
int fun1(){
    static int counter=0;
    if(counter!=7){
        counter++;
        return 2*(fun1() +1);
    } else{
        return 2;
    }
}
int main() {
    int sum,delta;
    sum=fun1();
    printf("sum=%d\n",sum);
    for (int i = 0; i < 8&&sum>2; ++i,sum-=delta) {
        delta=(sum/2)+1;
        printf("sell=%d,",delta);
    }
    printf("\n");
}//
// Created by Lenovo on 2025/12/2.
//
