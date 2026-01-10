#include <stdio.h>
int main(){
    int line,delta;
    char ch,c;
    scanf("%c%d",&ch,&line);
    c=ch;
    for(int i=1;i<=2*line-1;i++){
        delta=line-i;
        if(delta<0) delta=-delta;
        ch=c+line-delta-1;

        for (int j = 1; j <= 2*line-1-delta; j++) {
            if(j<=delta) printf(" ");
            else {if(j==delta+1||j==2*line-1-delta) printf("%c",ch);
                else printf(" ");
            }
        }
        printf("\n");
    }
}