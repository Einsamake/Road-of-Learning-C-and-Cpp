#include <ctype.h>
#include <stdio.h>

int convert(char letter) {
    while (letter >'Z') {
        letter = letter - 26 ;
    }return letter;
}
int main() {
    char letter='Y';
    int n=11;
    scanf("%d %c", &n,&letter);
    if (n%2==0||!isalpha(letter)) {
        printf("input error!\n");
        return 0;
    }
    letter=toupper(letter);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (i==0||i==n-1) {
                printf("%c",convert(letter+i+j));
            }
            else if (j==0||j==n-1||j==(n-1)/2) {
                printf("%c",convert(letter+i+j));
            }
            else printf(" ");
        }
        printf("\n");
    }
}
