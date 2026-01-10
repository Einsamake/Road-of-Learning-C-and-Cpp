#include "stdio.h"
#define P_ROUND 5
int leap_year( int );
int year_days( int );
int days(int,int,int);

typedef struct ban {
    int first;
    int second;
}ban;

int leap_year( int year )   // 判断闰年或平年
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;
}

int year_days(int year)     // 计算一整年的天数
{   return leap_year( year ) ? 366 : 365;
}

int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if  ( leap_year( year ) && month >2 )
        day++;

    for (int i=1; i<month; i++ )
        day += months[i];

    return day;
}
int main() {
    int year[2],month[2],date[2],numday[2];
    int d_date=0;
    year[0]=2012;
    month[0]=4;
    date[0]=9;
    numday[0]= days(year[0],month[0],date[0]);
    scanf("%d%d%d",&year[1],&month[1],&date[1]);
    numday[1]= days(year[1],month[1],date[1]);
    if(year[0]==year[1]){
        d_date=numday[1]-numday[0];
    } else{
        for (int i = year[0]+1; i < year[1]; ++i) {
            d_date += year_days(i);
        }
        d_date+=year_days(year[0])- numday[0]+numday[1];
    }
    int week_day=d_date%7,round=d_date/7 /13 %P_ROUND;//0开始
    if (week_day==5||week_day==6) {
        printf("Free.\n");
        return 0;
    }
    ban *p[P_ROUND], b[P_ROUND];
    int temp,exchange=0;

    for(int i=0 ,start=3; i < P_ROUND ;i++) {
        p[i]=&b[i];
        if (exchange==0) {
            b[i].first=start;
            b[i].second=(start++)+P_ROUND;
            if (b[i].second>=10) {
                b[i].second%=10;
                exchange=1;
            }
        }
        else {
            b[i].first=start-P_ROUND;
            b[i].second=start++;
        }
    }
    for(int i=0; round>0 &&i < P_ROUND ;i++) {
        if (i-round>=0) {
            p[i]-=round;
        }else {
            p[i]+=5-round;
        }
    }
    printf("%d and %d.\n",p[week_day]->first,p[week_day]->second);


}