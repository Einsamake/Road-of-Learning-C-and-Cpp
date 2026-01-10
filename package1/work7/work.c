
int leap_year( int );
int year_days( int );
int days(int,int,int);
#include "stdio.h"
int main(){
    int d_year,year[2],month[2],date[2],numday[2];
    for (int i = 0; i < 2; ++i) {
        scanf("%d%d%d",&year[i],&month[i],&date[i]);
    }
    numday[0]= days(year[0],month[0],date[0]);
    numday[1]= days(year[1],month[1],date[1]);
    if(year[0]==year[1]){
        printf("%d days\n",numday[1]-numday[0]);
    } else{
        d_year=year[1]-year[0]-1;


    }

}
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