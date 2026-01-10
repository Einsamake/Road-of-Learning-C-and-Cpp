#include <stdio.h>
int main(){
    int a,n,result;
    unsigned int num;
    scanf("%d%d",&a,&n);
    num=a;
    if(n==0){
        printf("The last 3 numbers is 1.\n");
    }
    else if(n==1){
        num=a%10;
        printf("The last 3 numbers is %d.\n",num);
    }
    else {
        for(int i=2;i<=n;i++){
            num=num*a;
            if(num>=36695){
                n=n/1000;
            }

        }

        printf("The last 3 numbers is %03d.\n",num%1000);
    }
}