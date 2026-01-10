#include "stdio.h"
int main(){
    int num,line,fir,last;
    scanf("%d%d",&num,&line);
    last=(num+3*line-3-1)%10;
    for(int i =1;i<=line;i++){
        for (int j =1; j <=line; j++) {
            if(i==1||j==line-i+1){
                printf("%d",num++);
                if(num>=10)num%=10;
            } else if(i!=line&&j==1){
                printf("%d",last--);
                if(last<0)last%=10;
            } else{
                printf(" ");
            }
        }
        printf("\n");
    }
}