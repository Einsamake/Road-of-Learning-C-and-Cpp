#include "stdio.h"

int main(){
    int n,flag=0,m;
    scanf("%d",&n);
    int que1[2*n],que2[2*n];
    for (int i = 0; i < 2*n; i++) {
        que1[i]=i;
    }
    for ( m = 0;flag==0 ; m++) {
        for (int i = 0; i < 2*n; i++) {
            que2[i]=que1[i];//记录前一个
        }
        for (int i = 1,k=0; i < 2*n; i+=2,k++) {
            que1[i]=que2[k];
        }
        for (int i = 0,k=n; i < 2*n; i+=2,k++) {
            que1[i]=que2[k];
        }
        for (int i = 0; i < 2*n; i++) {
            if(que1[i]==i)flag=1;
            else {
                flag=0;
                break;
            }
        }
    }
    printf("%d",m);
}