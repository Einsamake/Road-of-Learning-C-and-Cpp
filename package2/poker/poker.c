#include "stdio.h"
#include "string.h"
int first(char a){
        switch (a) {
            case 'H':return 3000;
            case 'S':return 1000;
            case 'D':return 400;
            case 'C':return 100;
            default: return 10000;
        }
}
int second(char b){
    if((b>='2')&&(b<='9'))return (int)(b-'0');
    else if(b=='0')return 10;
    else{
        switch (b) {
            case 'J':return 11;
            case 'Q':return 12;
            case 'K':return 13;
            case 'A':return 14;
            default: return 10000;
        }
    }
}
void sort(int num1[],char card1[]){
    int s=0,tmp;
    char tmp1,tmp2;
    for (int i = 0; i < 3; ++i) {
        s=i;
        for (int j = i+1; j < 3; ++j) {
            if(num1[s]<num1[j])s=j;
        }
        if(s!=i){
            tmp=num1[i];
            tmp1=card1[i*3];
            tmp2=card1[i*3+1];

            num1[i]=num1[s];
            card1[i*3]=card1[s*3];
            card1[i*3+1]=card1[s*3+1];

            num1[s]=tmp;
            card1[s*3]=tmp1;
            card1[s*3+1]=tmp2;
        }
    }
}
int sum(const int num[]){
    int s=0;
    for (int i = 0; i < 3; ++i) {
        s+=num[i];
    }
    return s;
}
void chu10(char ch[]) {
    int len = strlen(ch),flag;
    for (int i=0; i<len - 1;i++) {
        if (ch[i]=='1'&&ch[i+1]=='0') {
            ch[i] = '0';
            for (int j =i+1; j < len - 1; j++) {
                ch[j] = ch[j+1];
            }
            ch[len-1] = '\0';
            len--;
            break;
        }
    }
}
void restore10(char card[]) {
    int len = strlen(card);
    for (int i = 0; i < len; i++) {
        if (card[i] == '0' && (i+1 >= len || card[i+1] == ' ')) {
            for (int j = len + 1; j > i; j--) {
                card[j] = card[j-1];
            }
            card[i] = '1';
            card[i+1] = '0';
            break;
        }
    }
}
int main(){
    int num1[3],num2[3],flag=0;
    char card1[40];
    char card2[40];
    gets(card1);
    gets(card2);//01 34 67
    chu10(card1);
    chu10(card2);
    for (int i = 0,j=1,k=0; i < 8; i+=3,j+=3,k++) {
        num1[k]= first(card1[i])+ second(card1[j]);
        num2[k]= first(card2[i])+ second(card2[j]);
        if(num1[k]>10000||num2[k]>10000){
            printf("Input Error!\n");
            return 0;
        }
    }
    if(num1[0]==num1[1]||num1[1]==num1[2]||num1[0]==num1[2]){
        printf("Input Error!\n");
        return 0;
    }if(num2[0]==num2[1]||num2[1]==num2[2]||num2[0]==num2[2]){
        printf("Input Error!\n");
        return 0;
    }
    sort(num1,card1);
    sort(num2,card2);
    if(sum(num1)==sum(num2)){
        printf("Winner is X!\n");
    }
    else if(num1[0]>num2[0]){
        printf("Winner is A!\n");
    }else if(num1[0]<num2[0]){
        printf("Winner is B!\n");
    } else{
        for (int i = 0; i < 3; ++i) {
            if(num1[i]>num2[i]){
                printf("Winner is A!\n");
                break;
            }
            else if(num1[i]<num2[i]){
                printf("Winner is B!\n");
                break;
            }
        }
    }
    restore10(card1);
    restore10(card2);
    printf("A: ");
    puts(card1);
    printf("B: ");
    puts(card2);
}