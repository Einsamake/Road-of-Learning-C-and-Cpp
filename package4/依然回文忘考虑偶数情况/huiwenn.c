#include <stdio.h>
#include <string.h>
#define LEN 10000
int judge(char *str,int i,int j) {
    if(str[i]==str[j]&&i!=j) {
        return judge(str,i+1,j-1);
    }else if (i==j||i>j) {
        return 1;
    }else return 0;

}

int main() {
    char str[LEN]={0};
    gets(str);
    if (strlen(str)==0||strlen(str)==1) {
        printf("Yes\n");
        return 0;
    }
    int m=judge(str,0,strlen(str)-1);
    if (m==0) {
        printf("No\n");
    }else {
        printf("Yes\n");
    }
}