#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#define N 4
void print_spiral(int *mat,int n) {
    int matrix[N][N];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            matrix[i][j]=mat[i*N+j];
        }
    }

    static int counter=0;
    static int flag=0;
    int flag_up=counter,flag_down=n-1;
    if (n<0)flag=1;
    if (flag==1)return;
    printf("\ncounter=%d\nn=%d\n",counter,n);
    for(int i=counter;i<n-1;i++) {
        printf("%d ",matrix[flag_up][i]);
    }
    printf("\n");
    for(int i=counter;i<n-1;i++) {
        printf("%d ",matrix[i][flag_down]);
    }
    printf("\n");
    for(int i=n-1;i>counter;i--) {
        printf("%d ",matrix[flag_down][i]);
    }
    printf("\n");
    for(int i=n-1;i>counter;i--) {
        printf("%d ",matrix[i][flag_up]);
    }
    counter++;
    print_spiral(mat,n-1);
}
int main() {
    int matrix[N*N];
    int counter=0;
    for(int i=0;i<N*N;i++) {
        matrix[i]=counter++;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%2d ",matrix[i*N+j]);
        }
        printf("\n");
    }
    printf("\n");
    print_spiral(matrix,N);
}
