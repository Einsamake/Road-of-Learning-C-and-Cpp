#include "stdio.h"
int leap_year( int );
int year_days( int );
int days(int,int,int);

int leap_year( int year )   // 判断闰年或平年
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;
}

int year_days(int year)     // 计算一整年的天数
{   return leap_year( year ) ? 366 : 365;
}

int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;

    if  ( leap_year( year ) && month >2 )
        day++;

    for ( i=1; i<month; i++ )
        day += months[i];

    return day;
}
int main(){
    int year[2],month[2],date[2],numday[2];
    int d_year,d_date=0;
    for (int i = 0; i < 2; ++i) {
        scanf("%d%d%d",&year[i],&month[i],&date[i]);
        numday[i]= days(year[i],month[i],date[i]);
    }
    if(year[0]==year[1]){
        printf("%d days\n",numday[1]-numday[0]);
    } else{
        for (int i = year[0]+1; i < year[1]; ++i) {
            d_date += year_days(i);
        }
        d_date+=year_days(year[0])- numday[0]+numday[1];
        printf("%d days\n",d_date);
    }

}//
// Created by Lenovo on 2025/11/27.
//
