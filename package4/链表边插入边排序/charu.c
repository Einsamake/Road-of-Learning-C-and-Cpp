
#include "stdio.h"
#include "stdlib.h"
struct node
{   int data;
    struct node * next;
} ;

typedef struct node NODE;
typedef struct node * PNODE;
void outlist( PNODE );
void sortlist( PNODE, int);

int main ( )
{   int num=1;
    PNODE head;
    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;

    while ( num!=0 )
    {   scanf("%d", &num);
        if ( num!=0 )
            sortlist( head, num);
    }
    outlist( head );
    PNODE current=head;
    while ( current!=NULL ) {
        PNODE temp=current->next;
        free(current);
        current=temp;
    }
    return 0;
}

void outlist( PNODE head )
{   PNODE p;
    p = head->next;
    while ( p != NULL )
    {   printf("%d\n", p->data);
        p = p->next;
    }
}
void sortlist( PNODE head, int num) {
    PNODE p=head,pre=head;
    PNODE newnode = malloc(sizeof(NODE));
    newnode->data = num;
    while (p!=NULL) {
        if ( p->data==num) {
            free(newnode);
            return;
        }
        if (newnode->data<p->data) {
            newnode->next = pre->next;
            pre->next = newnode;
            return;
        }
        pre=p;
        p=p->next;
    }
    newnode->next = NULL;
    pre->next = newnode;
}