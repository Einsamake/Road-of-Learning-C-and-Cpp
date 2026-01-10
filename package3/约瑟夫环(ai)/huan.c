#include <stdio.h>
int j(int all,int num) {
    if (all!=1) {
        return (j(all-1,num)+num)%all;
    }else {
        return 0;
    }

}
int main() {
    int all,num;
    scanf("%d%d",&all,&num);
    printf("%d",j(all,num));






    /*int n, m;
    scanf("%d %d", &n, &m);

    int children[51] = {0};
    int remaining = n;
    int count = 0;
    int index = 0;
    while (remaining > 1) {
        if (children[index] == 0) {
            count++;
            if (count==m) {
                children[index]=1;
                remaining--;
                count=0;
            }
        }
        index=(index+1) % n;
    }
    for (int i = 0; i < n; i++) {
        if (children[i] == 0) {
            printf("The left child is NO %d.\n", i + 1);
            break;
        }
    }

    return 0;*/
}