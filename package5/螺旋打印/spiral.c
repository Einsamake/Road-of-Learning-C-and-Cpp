#include <stdio.h>
#include <stdlib.h>
#define N 9
void print_spiral(int n) {
    int matrix[n][n];
    int counter=1;
    int start=0;
    int size=n;
    while (n>start) {
        for (int i=start; i<n-1; i++) {
            matrix[start][i]=counter++;
        }//右
        for (int i=start; i<n-1; i++) {
            matrix[i][n-1]=counter++;
        }//下
        for (int i=n-1; i>start; i--) {
            matrix[n-1][i]=counter++;
        }//左
        for (int i=n-1; i>start; i--) {
            matrix[i][start]=counter++;
        }//上
        n--;
        start++;
    }
    if (size%2==1) {
        matrix[n][n]=counter++;
    }
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%2d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n=N;
    //scanf("%d",&n);
    print_spiral(n);
}
