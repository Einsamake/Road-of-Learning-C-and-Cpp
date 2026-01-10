#include <stdio.h>
#include <stdlib.h>
typedef struct numLink
{
    int no;
    struct numLink *next;
}NODE;

NODE *MoveNode( NODE * );

void SetLink( NODE *h )
{
    NODE *p=NULL, *q=NULL;
    int m;
    while(1)
    {
        scanf("%d",&m);
        if( m == -1 )
            return ;
        p = (NODE *)malloc(sizeof(NODE));
        p->no = m;
        p->next = NULL;
        if( h->next == NULL )
        {
            h->next = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = q->next;
        }
    }
    return;
}

int main( )
{
    NODE *head=NULL, *q=NULL;
    head = (NODE *)malloc(sizeof(NODE));
    head->no = -1;
    head->next = NULL;

    SetLink( head );
    q = MoveNode( head );
    do
    {
        printf("%d ",q->next->no);
        q = q->next;
    }while( q->next != NULL );
    printf("\n");
    return 0;
}
NODE *MoveNode( NODE *head ) {
    NODE *q=head,*p=head, *last=head,*pre=head,*move;
    NODE *arr[100]={NULL};
    int k=0;
    while(q!=NULL) {
        if (q->no%2==1) {
            pre=q;
        }
        q=q->next;
    }
    while(p!=NULL){
        move = p;
        p=p->next;
        if (p==NULL)break;
        if (p->no%2==0) {
            arr[k++] = p;
            move->next = p->next;
            p->next = NULL;
            p=move;
        }
    }
    for(int i=1;arr[i]!=NULL;i++) {
        arr[i-1]->next = arr[i];
        arr[i]->next = NULL;
    }
    pre->next = arr[0];
    return head;
}//
// Created by Lenovo on 2026/1/9.
//