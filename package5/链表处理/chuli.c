#include <stdio.h>
#include <stdlib.h>

typedef struct sdata {
    int num;
    struct sdata *next;
} SNODE;

void movenode(SNODE *, int);

void setlink(SNODE *head, int n) {
    SNODE *p;

    while (n > 0) {
        p = (SNODE *) malloc(sizeof(SNODE));
        p->num = n;
        p->next = head->next;
        head->next = p;
        n--;
    }
}

void outlink(SNODE *head) {
    while (head->next != NULL) {
        head = head->next;
        printf("%d,", head->num);
    }
    return;
}

int main() {
    int n, m;
    SNODE *head = NULL;

    scanf("%d%d", &n, &m);
    head = (SNODE *) malloc(sizeof(SNODE));
    head->num = -1;
    head->next = NULL;
    setlink(head, n);

    movenode(head, m); /* This is waiting for you. */

    outlink(head);
    printf("\n");
    return 0;
}
void movenode(SNODE *head, int n) {
    SNODE *p=head,*q=head,*pre=head;
    int counter=0,temp=0;
    while (p!=NULL) {
        p=p->next;
        temp++;
    }
    p=head;
    if (n==0||n>temp)return;
    while (counter<n) {
        pre=p;
        p=p->next;
        counter++;
    }
    pre->next=p->next;
    p->next=head->next;
    head->next=p;
}//
// Created by Lenovo on 2025/12/25.
//