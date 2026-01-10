#include <stdio.h>
struct table {
    char input;
    char output;
};
struct table translate[]={
    'a','d',
    'b','w',
    'c','k',
    'd',';',
    'e','i',
    'i','a',
    'k','b',
    ';','c',
    'w','e'
};
int main() {
    char ch;
    while((ch=getchar())!='\n') {
        int i;
        int size=sizeof(translate)/sizeof(struct table);
        for (i=0;i<size&&translate[i].input!=ch;i++);
        if(i<size) {
            putchar(translate[i].output);
        }else {
            putchar(ch);
        }
    }printf("\n");
}/*输入 a b c d e i k ; w

输出 d w k ; i a b c e*///
// Created by Lenovo on 2025/12/16.
//