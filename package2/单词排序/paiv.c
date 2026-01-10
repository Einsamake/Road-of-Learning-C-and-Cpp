#include "stdio.h"
#include "string.h"
int main(){
    char str[5][40],temp[40];int s;
    for (int i = 0; i < 5; ++i) {
        gets(str[i]);
    }
    for (int i = 0; i < 5; ++i) {
        s=i;
        for (int j = i+1; j < 5; ++j) {
            if(strcmp(str[s],str[j])<0){
                s=j;
            }
        }
        if(s!=i){
            strcpy(temp,str[i]);
            strcpy(str[i],str[s]);
            strcpy(str[s],temp);
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("%s\n",str[i]);
    }
}
