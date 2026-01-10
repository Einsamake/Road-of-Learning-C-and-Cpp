#include <stdio.h>
void reset(int *used_number){
    for (int i = 0; i < 10; ++i) {
        used_number[i]=i;
    }
}
int check_equal(const int * hundred,const int * ten,const int * one,int i){
    if(hundred[i]==ten[i]||ten[i]==one[i]||one[i]==hundred[i]){
        return 1;
    } else return 0;
}
int main() {
    int num,num2,num3;
    int hundred[3],ten[3],one[3];
    int used_number[10];
    for (int i = 0; i < 9; ++i) {
        used_number[i]=i+1;
    }
    scanf("%d",&num);
    if(num>3){
        printf("0,0,0\n");
    }
    for (int i = num*100; i < ((num==3)?333:num*100+99); ++i) {
        hundred[0]=num;ten[0]=i/10%10;one[0]=i%10;
        if(check_equal(hundred,ten,one,0)){
            continue;
        }
        used_number[hundred[0]]=0;used_number[ten[0]]=0;used_number[one[0]]=0;


        num2=i*2;
        hundred[1]=num2/100;ten[1]=num2/10%10;one[1]=num2%10;
        if(check_equal(hundred,ten,one,1)){
            continue;
        }
        if(used_number[hundred[1]]==0||used_number[ten[1]]==0||used_number[one[1]]==0){
            reset(used_number);
            continue;
        }
        else used_number[hundred[1]]=0;used_number[ten[1]]=0;used_number[one[1]]=0;


        num3=i*3;
        hundred[2]=num3/100;ten[2]=num3/10%10;one[2]=num3%10;
        if(check_equal(hundred,ten,one,2)){
            reset(used_number);
            continue;
        }
        if(used_number[hundred[2]]==0||used_number[ten[2]]==0||used_number[one[2]]==0){
            reset(used_number);
            continue;
        }
        printf("%d,%d,%d\n",i,num2,num3);
    }


}//
// Created by Lenovo on 2025/12/2.
//
