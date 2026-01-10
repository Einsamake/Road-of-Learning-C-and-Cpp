#include <stdio.h>
#include "string.h"
#define N 18
int work(char id[N]){
    int weight[]={7 ,9 ,10 ,5 ,8 ,4 ,2 ,1 ,6 ,3,7,9,10,5,8,4,2};
    char exam[]={'1' ,'0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2'};
    char new[N+1];
    int num[N],sum=0,code;
    for (int i = 0; i < N; ++i) {
        id[i]=id[i];
    }
    if(strlen(id)==18){
        for (int i = 0; i < N-1; ++i) {
            num[i]=weight[i]*(int)(id[i]-'0');
        }
        for (int i = 0; i < N-1; ++i) {
            sum+=num[i];
        }
        code=sum%11;
        if(exam[code]==(id[N-1])){
            printf("Valid\n");
        } else printf("Invalid\n");
        return 0;
    } else if(strlen(id)==15){
        for (int i = 0; i < 6; ++i) {
            new[i]=id[i];
        }
        for (int i = N-2; i >7; i--) {
            new[i]=id[i-2];
        }
        if((id[strlen(id)-3]=='9')&&(id[strlen(id)-2]=='9')&&((id[strlen(id)-1]<='9')&&(id[strlen(id)-1]>='6'))){
            new[6]='1';new[7]='8';
        } else {
            new[6]='1';new[7]='9';
        }
        for (int i = 0; i < N-1; ++i) {
            num[i]=weight[i]*(int)(new[i]-'0');
        }
        for (int i = 0; i < N-1; ++i) {
            sum+=num[i];
        }
        code=sum%11;
        new[N-1]=exam[code];
        new[N]='\0';
        puts(new);
        return 0;
    } else {printf("Invalid\n");return 0;}
}

int main(){//350622197904130331 11010519491231002X 110105491231002 110105491231996
    int n;
    scanf("%d",&n);
    getchar();
    char id[n][N];
    for (int i = 0; i < n; ++i) {
        scanf("%s",id[i]);
        work(id[i]);
    }
}


