#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
long findf(int n){
    if(n<=0)return 1;
    else return n*findf(n-1)+findf(n-2);
}
typedef struct output{
    char data[N];
    struct output* next;
}output;

void create(output* head,char word[N]) {
    int flag=0;
    output* temp = (output*)malloc(sizeof(output));
    strcpy(temp->data,word);
    temp->next = NULL;
    output* current = head;
    output* previous = current;
    while( current!=NULL&&strcmp(temp->data,current->data)>0) {
        previous = current;
        current = current->next;
        if (current == NULL) {
            previous->next = temp;
            flag=1;
            break;
        }
    }

    if (flag==1) return;
    temp->next = previous->next;
    previous->next = temp;
}
int main() {
    int i=0;
    char dict[N][N],word[N];
    output* head=(output*)malloc(sizeof(output));;
    head->next=NULL;
    head->data[0]='\0';
    char s[2]=" ";
    gets(word);
    char *token=strtok(word,s);
    printf("%s",token);
    while (1)  {
        token=strtok(NULL,s);
        if (token==NULL)break;
        create(head,token);
    }
    output* p=head->next;
    while (p!=NULL) {
        output* previous=p;
        printf(" %s",p->data);
        p=p->next;
    }
    printf("\n");
}
//
// Created by Lenovo on 2026/1/6.
//