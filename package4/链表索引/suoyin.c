#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct NODE {
    char data;
    struct NODE *next;
}NODE;
typedef struct NODE* PNODE;

PNODE init() {
    PNODE head=malloc(sizeof(NODE));
    head->next=NULL;
    return head;
}

void add(PNODE *tail,char letter) {
    PNODE newnode=malloc(sizeof(NODE));
    newnode->data=letter;
    newnode->next=NULL;
    (*tail)->next=newnode;
    (*tail)=newnode;
}

void free_malloc(PNODE *head) {
    PNODE p,current=*head;
    while (current!=NULL) {
        p=current->next;
        free(current);
        current=p;
    }
}
int main() {
    PNODE head=init();
    int dict[128]={0};
    char letter[8]={'a', 'b', 'c', 'd', 'c', 'b' , 'a','\0'};
    PNODE tail=head;
    for (int i=0;i<7;i++) {
        dict[letter[i]]++;
        add(&tail,letter[i]);
    }
    char input=getchar();
    PNODE current=head->next;
    if (isdigit(input)) {
        if (input>'6') {
            printf("N\n");

        }else{
            for (int i=0;i<input-'0';i++,current=current->next);
            printf("%c",current->data);
        }
    }else {
        for (int i=0,counter=0;i<7;i++,current=current->next) {
            if (current->data==input) {
                counter++;
                if(counter==dict[input]) {
                    printf("%d",i);
                }
            }
        }
    }
    free_malloc(&head);
    return 0;
}