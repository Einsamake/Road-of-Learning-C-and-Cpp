#include <stdio.h>
#include "string.h"
#define N 100
int main(){
    int row,col,flag=0;
    scanf("%d%d",&row,&col);
    int mtx[row][col], mtx2[row][col],mtx3[row][col];
    memset(mtx2, 0, sizeof(mtx2));
    memset(mtx3, 0, sizeof(mtx3));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d",&mtx[i][j]);
        }
    }
    for(int k = 0; k<row ; ++k){
        for(int i = 0; i<col ; ++i){
            for (int j = i; j < col; ++j) {
                if(mtx[k][i]<mtx[k][j]){
                    flag=1;break;
                }
            }
            if(flag==0){
                mtx2[k][i]=mtx[k][i];
                break;
            }
            flag=0;
        }
    }
    for(int k = 0; k<col ; ++k){
        for(int i = 0; i<row ; ++i){
            for (int j = i; j < row; ++j) {
                if(mtx[i][k]>mtx[j][k]){
                    flag=1;break;
                }
            }
            if(flag==0){
                mtx3[i][k]=mtx[i][k];
                break;
            }
            flag=0;
        }
    }
    for(int i = 0; i<row ; ++i) {
        for (int j = 0; j < col; ++j) {
            if(mtx2[i][j]==mtx3[i][j]&&mtx2[i][j]!=0){
                printf("Point:a[%d][%d]==%d\n",i,j,mtx2[i][j]);
                return 0;
            }
        }
    }
    printf("No Point\n");
}