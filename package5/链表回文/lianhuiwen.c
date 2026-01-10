#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//构造结构体
typedef struct list
{
    char data;
    struct list *next;
}*List,LNode;

//函数声明
List init_list(List head);
int chkPalindrome(List head);

int main()
{
    List head;
    head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    head = init_list(head);
    if(chkPalindrome(head))
        printf("yes\n");
    else
        printf("no\n");

}

//链表初始化函数
List init_list(List head)
{
    int i = 0;
    List p = head;

    char chain[1000];
    memset(chain, 0, 1000 * sizeof(char));
    gets(chain);

    while(chain[i]!='\0')
    {
        List s;
        s = (LNode*)malloc(sizeof(LNode));
        s->data = chain[i];
        s->next = NULL;
        p->next = s;
        p = p->next;
        i++;
    }
    return head->next;
}
int chkPalindrome(List head){
    List p=head,p1=p,front=head;
    if (p==NULL)return 1;
    while(p->next!=NULL){
        p1=p;
        p=p->next;
    }
    if(p==front->next||p==front)return 1;
    else{
        if(front->data==p->data){
            p1->next=NULL;
            return chkPalindrome(front->next);
        }else return 0;
    }
}//
// Created by Lenovo on 2025/12/22.
//