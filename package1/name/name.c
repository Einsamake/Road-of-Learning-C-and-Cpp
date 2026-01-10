#include "stdio.h"
int main(){
    int s,tem,num[5]={1,3,9,2,5};
    for(int i=0;i<5;i++){
        s=i;
        for (int j = i+1; j < 5; j++) {
            if(num[s]>num[j])s=j;
        }
        if(s!=i){
            tem=num[s];
            num[s]=num[i];
            num[i]=tem;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d",num[i]);

    }
}