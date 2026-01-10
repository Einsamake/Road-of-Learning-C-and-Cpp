#include <stdio.h>


int countsub( char *s1, char *s2 );

int main( )
{
    char s1[1000] = {0}, s2[100] = {0};
    gets(s1);
    gets(s2);
    printf("%d\n", countsub( s1, s2 ) );
}
#include <string.h>
int countsub( char *s1, char *s2 ) {
    char *p = s1,*q=s2,*start=s1;
    int continuous = 0,count=-100;
    while (p-start<=strlen(s1)) {
        if (strncmp(p,q,strlen(s2)) == 0){
            p+=strlen(s2);
            continuous++;
        }else {
            p++;
            if (count<continuous) {
                count=continuous;
            }
            continuous=0;

        }
    }
    return count;
}//
// Created by Lenovo on 2026/1/9.
//