#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index;
    struct node *next;
}*PNODE,NODE;

void setLink(int n,PNODE head);

void deleteLink(int n,int k,PNODE head);
int main( ){
    PNODE head = (PNODE)malloc(sizeof(NODE));
    head->next = NULL;
    head->index = 0;
    int n,k;
    scanf("%d %d",&n,&k);
    setLink(n,head);
    deleteLink(n,k,head);
}
void deleteLink(int n,int k,PNODE head) {
    int count=0,countAll=0;
    PNODE p=head,pre=head;
    while(head->next!=NULL&&countAll<n-1) {
        pre=p;
        p=p->next;
        count++;
        if (count==k) {
            if (p==head->next) {
                head->next = p->next;
                printf("%d\n",p->index);
                free(p);
                count=0;
                countAll++;
                p=pre;
            }else {
                pre->next=p->next;
                printf("%d\n",p->index);
                free(p);
                count=0;
                p=pre;
                countAll++;
            }
        }
    }
    printf("%d\n",head->next->index);
}
void setLink(int n,PNODE head) {
    int count=0,index=1;
    PNODE p=head;
    while(count<n) {
        PNODE temp = (PNODE)malloc(sizeof(NODE));
        temp->index = index++;
        temp->next = head->next;
        p->next = temp;
        p = p->next;
        count++;
    }
}//
// Created by Lenovo on 2026/1/10.
//