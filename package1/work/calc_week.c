#include <stdio.h>

int main() {
    int year,month,date,after_days,days;
    scanf("%d%d%d",&year,&month,&date);
    scanf("%d",&after_days);
    while(after_days>0){
        switch (month) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                days=31;break;
            case 4:case 6:case 9:case 11:
                days=30;break;
            case 2:days=((year%4==0&&year%100!=0)|(year%400==0))?29:28;break;
        }
        if(month<=12){
            if(date<days){
                date++;after_days--;
            } else{month++;date=0;}}
        else{month=1;date=0,year++;}
    }
    printf("%d.%d.%d\n",year,month,date);
}