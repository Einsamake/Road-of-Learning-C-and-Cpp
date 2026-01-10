#include <stdio.h>
#include <string.h>


int main() {
    int num,team;
    scanf("%d",&num);
    for(int i=0;i<num;i++) {
        scanf("%d",&team);
        if (team==1) {
            printf("0\n");
            continue;
        }
        if(team%2==1) {
            printf("%d\n",team);
        }else if(team%2==0) {
            printf("%d\n",team-1);
        }
    }

}

