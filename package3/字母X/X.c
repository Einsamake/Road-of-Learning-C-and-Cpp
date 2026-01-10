#include <stdio.h>
#include "ctype.h"

int main( )
{
    int n,delta;
    char letter,p_letter;
    scanf("%d %c",&n,&letter);
    if(!isupper(letter)){
        printf("input error.\n");
        return 0;
    }
    for (int i = 0; i < 2*n-1; ++i) {
        if(i<=n-1){
            p_letter=letter+n-i-1;
            while (p_letter>'Z'){
                p_letter-=26;
            }
            for (int j = 0; j < 2*n-1-i; ++j) {
                if(j==i||j==2*n-i-2)
                    printf("%c",p_letter);
                else
                    printf(" ");
            }
        } else{
            p_letter=letter+n-i-1;
            while (p_letter<'A'){
                p_letter+=26;
            }
            for (int j = 0; j < i+1; ++j) {
                if(j==2*n-i-2||j==i)
                    printf("%c",p_letter);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}//
// Created by Lenovo on 2025/11/25.
//
