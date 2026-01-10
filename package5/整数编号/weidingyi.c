#include   <stdio.h>
#include <stdlib.h>

struct nn {
    int no;
    int num;
};

typedef struct nn DATA;

int number(char *, DATA []);

int main() {
    DATA b[100];
    char sa[500];
    int i, n;
    gets(sa);
    n = number(sa, b);
    for (i = 0; i < n; i++)
        printf("%d %d\n", b[i].num, b[i].no);
    return 0;
}

#include "string.h"
int number(char *str, DATA a[]) {
    char *p = str,num[5];int counter=0;//输入的数字是字符串形式
    int sa[101],sa1[101];   //sa[]：要排序的数组    sa1：原来输入顺序的数组
    for (int i=0;*p!='\0';i++,p++) {//这个for循环是用来把输入的数字(字符串)变成整数储存在数组里面的
        memset(num,0,sizeof(num));  //因为读取字符串只能一个一个读, num数组(是字符串)用来储存多位数比如14，100
                                            //memset函数初始化num[]数组
        int j=0,flag=0;
        while (*p!=' '&&*p!='\0') {//每个数字之间有空格隔开
            num[j++]=*p;
            p++;
            flag=1;//flag=1表示读到了数字
        }
        if (flag==1) {
            counter++;//看看有多少个数字
            sa[i]=atoi(num);//string.h库提供的atoi(alpha to int)函数直接将字符串转换成对应数字,“121”->121
            sa1[i]=atoi(num);
        }
        //if (*p=='\0')break;
    }
    int n=counter;//有n个数字，方便扫描
    for (int i = 1,j=0; i < n; ++i) {//选择排序sa[]数组
        if(sa[i-1]>sa[i]){
            int temp=sa[i];
            for (j = i-1;j>=0&&temp<sa[j] ; j--) {
                sa[j+1]=sa[j];
            }
            sa[j+1]=temp;
        }
    }
    //这个for循环来扫描,比如14 4 3 6 8 2 3 9被排序的2 3 3 4 6 8 9 14扫描
    //sa1[]中的sa1[0]=14第一个扫描，发现，sa1[0]=sa[7];那就说明14在这堆数字里面排第7+1=8个
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(sa1[i]==sa[j]) {//a是要打印的结构数组，不重要;
                sa[j]=-1001;//最小的数是1000,不可能出现1001
                printf("%d ",j+1);
                a[i].no=j+1;//排第j+1个
                a[i].num=sa1[i];//是a1里面的下标为i的数
                break;
            }
        }
    }printf("\n");
    return n;
}//14 4 3 6 8 2 3 9
