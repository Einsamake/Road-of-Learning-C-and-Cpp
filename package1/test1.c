/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct folder {
    int type; // 文件夹类型,1 是主文件夹,2 是子文件夹
    int no; // 文件夹编号,从1 开始顺序;对于不同的子文件夹都是从1 开始编号｡
    int count; // 如果是主文件夹表示其拥有的子文件夹数量
    char name[20]; // 文件夹名称,主文件夹为main-folder-编号,
    // 例如main-folder-1 为第一个主文件夹;
    // 子文件夹为sub-folder-主文件夹编号-子文件夹编号,
    // 例如sub-folder-1-1 为第一个主文件夹下的第一个子文件夹
    struct folder *link;
} FOLDER;

FOLDER *phead;
// 生成正序的带有头节点的链表,表示的是完整的文件夹项
void CreatFolder(int n) {
    FOLDER *p, *q;
    int count;
    int i, j;
    q = (FOLDER *) malloc(sizeof(FOLDER));
    q->link = NULL;
    phead = q;
    for (i = 1; i <= n; i++) {
        scanf("%d", &count);
        p = (FOLDER *) malloc(sizeof(FOLDER));
        p->type = 1;
        p->no = i;
        p->count = count;
        sprintf(p->name, "main-folder-%d", p->no);
        q->link = p;
        q = q->link;
        for (j = 1; j <= count; j++) {
            p = (FOLDER *) malloc(sizeof(FOLDER));
            p->type = 2;
            p->no = j;
            p->count = 0;
            sprintf(p->name, "sub-folder-%d-%d", i, j);
            p->link = NULL;
            q->link = p;
            q = q->link;
        }
    }
}

FOLDER *phead;

// 根据主文件夹中的count 个数,删除其节点后的子文件夹-------需要补全
void DeleteSubFolder(FOLDER *phead) {
    FOLDER *p=phead,*pre=phead;
    int sub_num;
    while (p) {
        char output[30];
        pre=p;
        if (strncmp(p->name,"sub",3)==0) {
            sprintf(output, "delete %s", p->name);
            printf("%s\n", output);
            pre->link = p->link;
            free(p);
            p=pre;
        }
        p=p->link;
    }
    while (p) {
        printf("%s\n", p->name);
        p=p->link;
    }
}


// 打印链表中节点内容
void PrintFolder(FOLDER *h) {
    FOLDER *q = h;
    q = q->link;
    while (q != NULL) {
        printf("%s\n", q->name);
        q = q->link;
    }
}

// 释放链表内存
void FreeFolder(FOLDER *h) {
    FOLDER *q = h, *p;
    q = q->link;
    while (q != NULL) {
        p = q;
        q = q->link;
        free(p);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    CreatFolder(n);
    DeleteSubFolder(phead);
    PrintFolder(phead);
    FreeFolder(phead);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
