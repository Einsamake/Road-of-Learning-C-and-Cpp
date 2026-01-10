#include <stdio.h>
#include <stdlib.h>

struct Node {
    char *name;
    int  score;
    struct Node *next;
};

struct Node *  connect(struct Node *x, struct Node *y, struct Node *z);

int main(int argc, char *argv[]) {
    struct Node a, b, c, *p;


    a.name = "LiPing";
    b.name = "LiuHai";
    c.name = "FengYun";
    scanf("%d,%d,%d", &a.score, &b.score, &c.score);
    p= connect(&a,&b,&c);
    printf("%s-%d\n",p->name,p->score);
    p=p->next;
    printf("%s-%d\n",p->name,p->score);
    p=p->next;
    printf("%s-%d\n",p->name,p->score);
    return 0;
}
struct Node * connect(struct Node *x, struct Node *y, struct Node *z)
{
    struct Node *nodes[3] = {x, y, z};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (nodes[j]->score < nodes[j+1]->score) {
                struct Node *temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
    }
    nodes[0]->next = nodes[1];
    nodes[1]->next = nodes[2];
    nodes[2]->next = NULL;
    return nodes[0];
}//
// Created by Lenovo on 2026/1/9.
//