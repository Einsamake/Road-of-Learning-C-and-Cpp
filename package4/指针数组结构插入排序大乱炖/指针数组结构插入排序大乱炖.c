#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct Student {
    char name[20];
    int grade;
}Student;

int main() {
    int n;
    char ch;
    scanf("%d",&n);
    getchar();
    Student* student=(Student *)malloc(sizeof(Student)*n);
    Student* p_stu=student;
    for( ; p_stu-student<n ; p_stu++) {
        int i=0;
        memset(p_stu->name,0,20);
        while ( (ch = getchar())!=',' ) {
            p_stu->name[i++]=ch;
        }
        scanf("%d",&p_stu->grade);
        getchar();
    }
    for (int i=1,j;i<n;i++) {
        if (student[i].grade>student[i-1].grade) {
            Student temp=student[i];
            for ( j=i-1 ; j>=0 && student[j].grade<temp.grade ; --j ) {

                student[j+1]=student[j];
            }
            student[j+1]=temp;
        }
    }
    for (int i=0 ; i < n; i++) {
        printf("%s,%d\n",student[i].name,student[i].grade);
    }
    free(student);
}//
// Created by Lenovo on 2025/12/21.
//