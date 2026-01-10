#include <stdio.h>

int main()
{
    int max=-100,min=30000,num;
    char ch='0',op;
    while (ch!='\n')
    {
        ch=getchar();
        if(ch>='0'&&ch<='9')
        {
            num=ch-'0';
            if(max<=num){
                max=num;
            }
            if(min>=num){
                min=num;
            }
        } else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
        {
            op=ch;
        }
    }
    switch (op) {
        case '+':
            printf("%d+%d=%d\n",max,min,max+min);
            break;
        case '-':
            printf("%d-%d=%d\n",max,min,max-min);
            break;
        case '*':
            printf("%d*%d=%d\n",max,min,max*min);
            break;
        case '/':{if (min!=0){
            printf("%d/%d=%d\n",max,min,max/min);
            break;
                    }else printf("Error!\n");
            break;}
        case '%':{if (min!=0){
                printf("%d%%%d=%d\n",max,min,max%min);
                break;
            }else printf("Error!\n");
            break;}
        default:    printf("Error!\n");
    }
}