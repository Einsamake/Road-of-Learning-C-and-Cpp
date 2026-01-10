#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
    char letter;
    struct NODE *next;
}NODE;
typedef struct NODE* PNODE;
int main() {
    PNODE head=(PNODE)malloc(sizeof(NODE));
    head->letter='1';
    head->next=NULL;
    for (char i='a';i<='z';i++) {
        PNODE p;
        p=(PNODE)malloc(sizeof(NODE));
        p->letter=i;
        p->next=head->next;
        head->next=p;
    }
    PNODE p1=head;int i;
    for (i=0 ; p1!=NULL; i++) {
        printf("%c",p1->letter);
        p1=p1->next;
    }
    printf("%d",i);
    PNODE current=head;
    while (current!=NULL) {
        PNODE next=current->next;
        free(current);
        current=next;
    }
}//
// Created by Lenovo on 2025/12/16.
//