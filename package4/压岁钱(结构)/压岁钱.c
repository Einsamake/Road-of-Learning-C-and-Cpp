#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMELEN 14

typedef struct Parent {
    char name[NAMELEN];
    int cash;
    int income;
}Parent;

int detect(const char *name,const Parent *parents,int number) {
    for (int i = 0; i < number; i++) {
        if (strcmp(name, parents[i].name) == 0) {
            return i;
        }
    }return 0;
}
int main() {
    int num,plan_give,give_people;
    scanf("%d",&num);
    Parent parents[num];
    char name_to_give[NAMELEN],name_be_give[NAMELEN];
    for (int i = 0; i < num; i++) {
        scanf("%s",parents[i].name);
        parents[i].cash = 0;
        parents[i].income = 0;
    }
    for (int i = 0; i < num; i++) {
        scanf("%s",name_to_give);
        int which=detect(name_to_give,parents,num);
        scanf("%d %d",&plan_give,&give_people);
        if (give_people!=0) {
            if (plan_give%give_people==0) {
                parents[which].cash -= plan_give;
                plan_give = plan_give / give_people;
            }else {
                parents[which].cash -= plan_give;
                parents[which].cash += plan_give%give_people;
                plan_give = plan_give / give_people;
            }
            //printf("%d %d %d\n",parents[i].cash,plan_give,give_people);
        }else {

            continue;
        }
        for (int j = 0; j < give_people; j++) {
            scanf("%s",name_be_give);
            which=detect(name_be_give,parents,num);
            parents[which].income+=plan_give;
            //printf("%s %d %d %d\n",name_be_give,parents[j].cash,plan_give,give_people);
        }

    }
    for (int i = 0; i < num; i++) {
        printf("%s %d",parents[i].name,parents[i].income+parents[i].cash);
        printf("\n");
    }

}//
// Created by Lenovo on 2025/12/18.
//