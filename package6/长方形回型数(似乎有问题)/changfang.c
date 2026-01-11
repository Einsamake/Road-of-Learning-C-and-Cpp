#include <stdio.h>
void print_spiral(int length,int width) {
    int arr[width][length],num=0;
    int l=length,w=width;int start=0;
    while (length>0&&width>0) {

        for (int i = start; i < length; i++) {
            arr[start][i] = num;
        }
        num++;
        if (start+1==width)break;
        for (int i = start+1; i < width; i++) {
            arr[i][length-1] = num;
        }
        num++;
        for (int i = length-2; i >= start; i--) {
            arr[width-1][i] = num;
        }
        num++;
        if (width-2==start)break;
        for (int i = width-2; i > start; i--) {
            arr[i][start] = num;
        }
        num++;
        length--;
        width--;
        start++;
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < l; j++) {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}

int main( ){
    int length,width;
    scanf("%d%d",&length,&width);
    print_spiral(length,width);
}

