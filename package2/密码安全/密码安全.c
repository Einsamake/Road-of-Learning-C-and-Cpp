#include <stdio.h>
#include "string.h"
#define N 20
int work(char pwd[]){
    int counter=0,flag[4]={0},pri[4]={0};
    if(strlen(pwd)<6){
        printf("Not Safe\n");
        return 0;
    }
    for (int i = 0; i < strlen(pwd); ++i) {
        if((pwd[i]<='Z'&&pwd[i]>='A')){
            flag[0]=1;

            pri[0]=1;
        }
        else if((pwd[i]<='z'&&pwd[i]>='a')){
            flag[1]=1;
            pri[1]=1;
        }
        else if((pwd[i]<='9'&&pwd[i]>='0')){
            flag[2]=1;
            pri[2]=1;
        }
        else {
            pri[3]=1;
        }
    }
    for (int i = 0; i < 4; ++i) {
        counter+=pri[i];
    }
    if(counter==1)printf("Not Safe\n");
    else if(counter==2)printf("Medium Safe\n");
    else if(counter>=3)printf("Safe\n");
    return 0;

}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char pwd[N];
    for (int i = 0; i < n; ++i) {
        gets(pwd);
        work(pwd);
    }


}