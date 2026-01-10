#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define MAX_LEN 81
#define DICT_LEN 50000
#define MAX_WORD_LEN 81
static char word_dict[DICT_LEN+1][MAX_WORD_LEN];
static int dict_index=1;
int main() {
    char word[MAX_LEN],zip[MAX_LEN*2];
    char temp[MAX_LEN];
    memset(word_dict,'\0',sizeof(word_dict));
    while (gets(word)!=NULL) {
        memset(zip,'\0',sizeof(zip));
        memset(temp,'\0',sizeof(temp));
        for (int j = 0,zip_index=0; j < strlen(word); ++j) {
            if (!isalpha(word[j])) {
                zip[zip_index++]=word[j];    //不是字母
            }else {                     //是字母
                int mark=j,flag=0;//开始记录,mark是单词最开始位置
                while (word[j]!='\0'&&isalpha(word[j])!=0) {
                    j++;//此时指向单词末尾结束后字符
                }
                int distance=j-mark;
                for (int l = 0,m=mark; l < distance; ++l) {
                    temp[l]=word[m++];
                }
                temp[distance]='\0';//记录单词
                for (int l = 1; l < dict_index; ++l) {  //查看在不在字典里面
                    if (strcmp(temp,word_dict[l])==0) {
                        if (l<10) {
                            zip[zip_index++]=l+'0';// 压缩文件里面就是对应字典索引值了
                            flag=1;// 标记1说明是在的
                            break;
                        }else if (l<100) {
                            zip[zip_index++]=l/10+'0';
                            zip[zip_index++]=l%10+'0';
                            flag=1;break;
                        }else if (l<1000) {
                            zip[zip_index++]=l/100+'0';
                            zip[zip_index++]=l/10%10+'0';
                            zip[zip_index++]=l%10+'0';
                            flag=1;break;
                        }else if (l<10000) {
                            zip[zip_index++]=l/1000+'0';
                            zip[zip_index++]=l/100%10+'0';
                            zip[zip_index++]=l/10%10+'0';
                            zip[zip_index++]=l%10+'0';
                            flag=1;break;
                        }else if (l<DICT_LEN) {
                            zip[zip_index++]=l/10000+'0';
                            zip[zip_index++]=l/1000%10+'0';
                            zip[zip_index++]=l/100%10+'0';
                            zip[zip_index++]=l/10%10+'0';
                            zip[zip_index++]=l%10+'0';
                            flag=1;break;
                        }
                    }
                }
                if (flag!=1) {//如果不在字典里面
                    strcpy(word_dict[dict_index++],temp);  //把单词记录到字典里面
                    for (int l = mark,m=0; l < j; ++l) {
                        zip[zip_index++]=temp[m++];//压缩文件就是对应单词
                    }
                }
                j--;
                memset(temp,'\0',sizeof(temp));
            }
        }
        puts(zip);
    }
}//
// Created by Lenovo on 2025/12/8.
//