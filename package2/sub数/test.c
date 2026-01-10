#include "stdio.h"
int main(){
    int num,sub1,sub2,sub3,a;
    scanf("%d",&a);
    for(int i=100;i<=300;i++){
        if(i%a==0){
            sub1=i;
            for (int j = sub1%100*10; j < sub1%100*10+10; j++) {
                if(j%a==0){
                    sub2=j;
                    for (int k = sub2%100*10; k < sub2%100*10+10; k++) {
                        if(k%a==0){
                            sub3=k;
                            printf("%d\n",sub1*100+sub3%100);
                        }
                    }
                }
            }
        }
    }
}