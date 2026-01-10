#include <stdio.h>


int main() {
    int n;
    scanf("%d",&n);
    int seq[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&seq[i]);
    }
    int *p=seq,*q=seq,max=-1;
    int *start=seq,put[2];
    while (q-start<n) {
        while(*p==*q) {
            q++;
        }
        if (q-p>max) {
            max=(int)(q-p);
            put[0]=(int)(p-start);
            put[1]=(int)(q-start);
        }
        p=q;
    }
    if (max==1)printf("No equal number list.\n");
    else printf("The longest equal number list is from %d to %d.\n",put[0],put[1]-1);

}//
// Created by Lenovo on 2025/12/8.
//