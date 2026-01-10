#include <stdio.h>
int main() {
    char n[21]={0};
    //FILE *fp=fopen("text1.txt","r");
    while(fgets(n,20,stdin)!=NULL) {
        n[20]='\0';
        for(int i=0;i<20;i++){
            if(n[i]=='n')
                n[i]='\n';
        }
        for(int i=19;i>0;i--) {
            if(n[i]=='\n'&&n[i+1]=='\n') {
                n[i]='\n';
                if(i==19) {
                    n[i+1]='\0';
                }else
                    for(int j=i+1;j<=19;j++) {
                        char temp=n[j];
                        n[j]=n[j+1];
                        n[j+1]=temp;
                    }
            }
        }
        fputs(n,stdout);
    }
}
//
// Created by Lenovo on 2025/12/29.
//