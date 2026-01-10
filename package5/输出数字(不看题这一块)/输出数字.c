#include <stdio.h>
#include <string.h>
typedef struct NUM {
    int number;
    int count;
}NUM;
int main() {
    int n,time,k=0;
    scanf("%d %d", &n,&time);
    NUM arr[n],temp;
    if (time>n) {
        printf("No such element.\n");
        return 0;
    }
    int has_print=0;
    for(int i=0;i<n;i++) {
        int flag=0;
        scanf("%d",&temp.number);
        for(int j=0;j<k&&i!=0;j++) {
            if(temp.number==arr[j].number) {
                arr[j].count++;
                if(arr[j].count>=time) {
                    printf("%d\n",arr[j].number);
                    arr[j].count=-32000;
                    has_print++;
                }
                flag=1;
                break;
            }
        }
        if(flag==1) continue;
        arr[k].number=temp.number;
        arr[k++].count=1;
        if(arr[k-1].count>=time) {
            printf("%d\n",arr[k-1].number);
            has_print++;
            arr[k-1].count=-32000;
        }
    }
    if(has_print==0) {
        printf("No such element.\n");
    }
}
//8 2
//1 1 2 3 2 2 1 4