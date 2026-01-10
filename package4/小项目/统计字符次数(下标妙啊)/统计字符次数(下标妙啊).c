#include <stdio.h>
#include "string.h"
#define LEN 120
int main() {
    char str[LEN];int count[128]={0},dict[128]={0};
    gets(str);
    for(int i=0;str[i]!='\0';i++) {
        count[str[i]]++;
    }
    for(int i=0;str[i]!='\0';i++) {
        dict[str[i]]++;
        if (dict[str[i]]==count[str[i]]&&dict[str[i]]<10&&count[str[i]]!=1) {
            str[i]=count[str[i]]+'0';
        }else if (dict[str[i]]==count[str[i]]&&count[str[i]]!=1) {
            for(int j=i+1;str[j]!='\0';j++) {
                str[j+1]=str[j];
            }
            str[i]=count[str[i]]/10+'0';
            str[i+1]=count[i]%10+'0';
        }
    }
    puts(str);
}