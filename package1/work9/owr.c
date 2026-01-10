#include <stdio.h>  
int main(){  
    char ch1,ch2;  
    int end1,end2;  
    ch1=getchar();  
    ch2=getchar();  
    end1=(ch1=='\n')?0:1;  
    end2=(ch2=='\n')?0:1;  
       while (end1 && end2) {  
        if (ch1 <= ch2) {  
            putchar(ch1);  
            ch1 = getchar();  
            if (ch1 == '\n') end1 = 0;  
        } else {  
            putchar(ch2);  
            ch2 = getchar();  
            if (ch2 == '\n') end2 = 0;  
        }  
    }  
    while (end1){  
        putchar(ch1);  
            ch1 = getchar();  
            if (ch1 == '\n') end1 = 0;  
    }  
    while (end2){  
        putchar(ch2);  
            ch2 = getchar();  
            if (ch2 == '\n') end2 = 0;  
    }  
    printf("\n");   
}  
