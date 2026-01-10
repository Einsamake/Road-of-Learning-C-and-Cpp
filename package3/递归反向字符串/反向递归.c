#include <stdio.h>
#include <stdlib.h>
void reverse(char[], int, int);
int main( )
{   char str[100];
    int start, end;
    gets(str);
    scanf("%d%d", &start, &end);
    reverse( str, start, end );
    printf("%s\n", str);
    return 0;
}
#include "string.h"
void reverse(char str[],int start,int end){
    int size= (int)strlen(str)-1;
    char temp;
    if(start<0)start=0;
    if(end<0)end=0;
    if(start> size)start=size;
    if(end>size)end=size;
    if( start!=end && end>start ){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        reverse(str,start+1,end-1);
    }
}
//
// Created by Lenovo on 2025/11/25.
//
