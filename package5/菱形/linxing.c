#include<stdio.h>
char deal(char letter) {
    while (letter>'Z' ) {
        letter-=26;
    }
    return letter;
}
int main()
{
    int n;
    char letter;
    scanf("%d %c",&n,&letter);
    int c=4*n-4;
    for(int i=0;i<2*n-1;i++) {
        if (i<n) {
            for(int j=0;j<n+i;j++) {
                if(j==n-i-1) {
                    printf("%c",deal(letter+i));
                }else if(j==n+i-1) {
                    printf("%c",deal(letter+c-i));
                }else {
                    printf(" ");
                }
            }
        }else {
            for(int j=0;j<3*n-i-2;j++) {
                if(j==i-n+1) {
                    printf("%c",deal(letter+i));
                }else if(j==3*n-i-3) {
                    printf("%c",deal(letter+c-i));
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}//
// Created by Lenovo on 2026/1/9.
//