#include <stdio.h>
typedef struct stu {
    int grade[4];
    float average;
}stu;
int main() {
    struct stu student[3];
    for(int i=0;i<3;i++) {
        float sum=0;
        for(int j=0;j<4;j++) {
            scanf("%d",&student[i].grade[j]);
        }
        for(int j=0;j<4;j++) {
            sum+=student[i].grade[j]*1.0;
        }student[i].average=sum/4.0;
    }
    int n;
    scanf("%d",&n);
    printf("%d",student[n-1].grade[0]);
    for(int j=1;j<4;j++) {
        printf(" %d",student[n-1].grade[j]);
    }
    printf("\n");
    if (student[n-1].average-(int)student[n-1].average==0) {
        printf("%d",(int)student[n-1].average);

    }
    else printf("%.2f",student[n-1].average);
    printf("\n");
}
//#include <stdio.h>
/*struct stu {
    int grade[4];
    double average;
};
int main() {
    struct stu student[3];
    for(int i=0;i<3;i++) {
        float sum=0;
        for(int j=0;j<4;j++) {
            scanf("%d",&student[i].grade[j]);
        }
        for(int j=0;j<4;j++) {
            sum+=student[i].grade[j]*1.0;
        }student[i].average=sum/4.0;
    }
    struct stu stu_ar[3];
    for(int i=0,max;i<3;i++) {
        max=i;
        for(int j=i+1;j<3;j++) {
            if(student[j].average>student[max].average) {
                max=j;
            }
        }
        if (max!=i) {
            struct stu temp=student[i];
            student[i]=student[max];
            student[max]=temp;
        }
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("%d,",student[i].grade[j]);
        }
        printf("%d",student[i].grade[3]);
        printf("\n");
    }
}*/