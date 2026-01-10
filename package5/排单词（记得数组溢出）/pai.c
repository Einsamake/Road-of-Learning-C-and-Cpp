#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
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
    if (word[0]=='\0') {
        printf("\n");
        return 0;
    }
    char *token=strtok(word,s);
    create(head,token);
    while (1)  {
        token=strtok(NULL,s);
        if (token==NULL)break;
        create(head,token);
    }
    output* p=head->next;
    int count=0;
    while (p!=NULL) {
        output* previous=p;
        if (count!=0) {
            printf(" ");
        }
        count++;
        printf("%s",p->data);

        p=p->next;
    }
    printf("\n");
}