#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char data;
    struct Node* next;

}Node;
typedef Node* pnode;
pnode init() {
    pnode head=(pnode)malloc(sizeof(Node));
    head->data='0';
    head->next=NULL;
    return head;
}
pnode add(pnode head) {
    char ch;
    pnode p=head;
    while((ch=getchar())!='\n') {
        if(ch==' ') continue;
        pnode new_node=(pnode)malloc(sizeof(Node));
        new_node->data=ch;
        p->next=new_node;
        p=new_node;
    }
    p->next=NULL;
    return head;
}
void free_malloc(const pnode *head) {
    pnode current=(*head);
    while(current!=NULL) {
        pnode p=current->next;
        free(current);
        current=p;
    }
}
int main() {
    pnode head1=init(),head2=init(),head3=init();
    head1=add(head1);
    head2=add(head2);

    pnode p1=head1->next,p2=head2->next,p3=head3;
    char ch;
    while (p1!=NULL||p2!=NULL) {
        if (p1==NULL) {
            ch=p2->data;
            p2=p2->next;
        }else if (p2==NULL) {
            ch=p1->data;
            p1=p1->next;
        }else {
            if (p1->data<p2->data) {
                ch=p1->data;
                p1=p1->next;
            }else if (p2->data<p1->data) {
                ch=p2->data;
                p2=p2->next;
            }else {
                ch=p2->data;
                p1=p1->next;
                p2=p2->next;
            }

        }

        pnode new_node=(pnode)malloc(sizeof(Node));
        new_node->data=ch;
        p3->next=new_node;
        p3=new_node;
    }p3->next=NULL;
    p3=head3;
    while(p3->next!=NULL) {
        if (p3->data=='0') {
            p3=p3->next;
            continue;
        }
        printf("%c ",p3->data);
        p3=p3->next;
    }
    printf("%c",p3->data);
    printf("\n");

    free_malloc(&head1);
    free_malloc(&head2);
    free_malloc(&head3);
}//
// Created by Lenovo on 2025/12/16.
//