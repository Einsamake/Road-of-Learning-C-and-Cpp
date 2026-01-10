#include <stdio.h>
#define N 4
int current[N];
void dfs(int depth,int start,int n[]){
    if(depth==3){
        for (int i = 0; i < depth; ++i) {
            printf("%d ",current[i]);
        }
        printf("\n");
    } else{
        for (int i = start; i < N; ++i) {
            current[depth]=n[i];
            dfs(depth+1,i+1,n);
        }
    }
}

int main( )
{
    int n[]={1,2,3,4};
    dfs(0,0,n);
}
//
// Created by Lenovo on 2025/11/27.
//
