#include <stdio.h>
#include <stdlib.h>

int main( ){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=1;i<n+1;i++) {
        arr[i-1]=i;
    }
    int person=0,cur=0,live=n;
    while(live>0) {
        if (arr[person]>0) {
            cur++;
        }
        if(cur==k) {
            printf("%d\n",arr[person]);
            arr[person]=-1;
            cur=0;
            live--;
        }
        person++;
        person%=n;
    }
}
