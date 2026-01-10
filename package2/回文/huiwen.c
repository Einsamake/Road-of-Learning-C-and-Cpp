#include "stdio.h"

int main(){
    int num[10]={0},k,n,j,flag=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        flag=0;
        k=-1;
        j=i*i*10;
        do{
            k++;j/=10;
            num[k]=j%10;
        } while (j/10!=0);
        for(int x=0,y=k;x<=y;x++,y--){
            if(num[x]==num[y]){
            }else{
                flag=1;
            }
        }
        if(flag==0){
            printf("%d\n",i);
        }
    }
}