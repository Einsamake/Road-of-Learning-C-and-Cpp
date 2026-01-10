#include <stdio.h>
#include "string.h"
#define N 10
int main() {
    char tmp,num[N];
    int s;
    gets(num);
    for (int i = 0; i < strlen(num); i++) {
        s=i;
        for (int j = i; j < strlen(num); j++) {
            if(num[s]<num[j]){
                s=j;
            }
        }
        if(s!=i){
            tmp=num[i];
            num[i]=num[s];
            num[s]=tmp;
        }
    }
    puts(num);

}
