#include <stdio.h>
int judge(int month,int year){
    switch (month) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            return 31;
        case 4:case 6:case 9:case 11:
            return 30;
        case 2:return ((year%4==0&&year%100!=0)|(year%400==0))?29:28;
    }

}
int main() {
    int year,month,week,counter=0,fmonth[10],k=0;
    long int r_year,d_date;
    long int year_date,month_date,days;
    scanf("%d",&year);
    r_year=(year-1901)/4-(year-1901)/100+(year-1601)/400;
    year_date=366*r_year+(year-1900-r_year)*365;
    month_date=0;
    for ( month = 1; month <= 12 ; ++month) {
        int i=month-1;
        if(i>0){
            days= judge(i,year);
            month_date+=days;
        }
        d_date=year_date+month_date+13;
        week=d_date%7;
        if(week==5){
            fmonth[k++]=month;
            counter++;
        }
        if(month==10){
            ;
        }
    }
    if(counter==1){
        printf("There is %d Black Friday in year %d.\n",counter,year);
        printf("It is:\n");
        printf("%d/%d/%d\n",year,fmonth[0],13);
    }
    else {
        printf("There are %d Black Fridays in year %d.\n",counter,year);
        printf("They are:\n");
        for (int i = 0; i < k; ++i) {
            printf("%d/%d/%d\n",year,fmonth[i],13);
        }
    }

}//
// Created by Lenovo on 2025/11/18.
//
