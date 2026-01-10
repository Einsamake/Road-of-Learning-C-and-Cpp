#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 100
#define MAXWORD 21
#define DICTLEN 10000

typedef struct word {
    char word[MAXWORD];
    int count;
} A_word;

void dict_init(A_word dict[]) {
    for (int i = 0; i < DICTLEN; i++) {
        memset(dict[i].word, '\0',MAXWORD);
        dict[i].count = 0;
    }
}
int compare(const void *a,const void *b) {
    A_word *word_a=(A_word*)a;
    A_word *word_b=(A_word*)b;
    if (word_a->count==word_b->count) {
        return strcmp(word_a->word,word_b->word);
    }else {
        return word_b->count-word_a->count;
    }
}
int main() {
    char str[N];
    char *p, *q;
    A_word dict[DICTLEN];
    int k = 0;
    dict_init(dict);
    while (fgets(str,sizeof(str),stdin) != NULL) {
        if (str[0]=='\n')break;
        p = str, q = str;

        while (*p!='\n') {
            int flag=0,len=0;
            char word[MAXWORD]={0};
            if (!isalpha(*p)) {
                p++;
                continue;
            }
            while (isalpha(*p)) {
                word[len++]=tolower((unsigned char)*p);
                p++;
            }
            word[len]='\0';
            if (word[0]=='\0')break;
            for (int i=0;i<=k;i++) {
                if (strcmp(dict[i].word,word)==0) {
                    dict[i].count++;
                    flag=1;
                    break;
                }
            }
            if (flag==0) {
                strcpy(dict[k].word,word);
                dict[k].count++;
                k++;
            }
            while (isspace(*p)||ispunct(*p)) {
                if (*p=='\n') {
                    break;
                }else p++;
            }
            q=p;
        }
    }
    qsort(dict,k,sizeof(A_word),compare);
    for (int i=0;i<k;i++) {
        printf("%s %d\n",dict[i].word,dict[i].count);
    }

}
