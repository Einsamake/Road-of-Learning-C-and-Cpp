#include <stdio.h>
int main(){
    int edge,count;
    scanf("%d",&edge);
    for(int i=1;i<=edge;i++)
    {
        for (int j = 1; j<=edge; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}