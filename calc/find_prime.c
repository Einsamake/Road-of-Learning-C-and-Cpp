#include <stdio.h>
#include "math.h"
int main(){
    long int num,wrong;
    scanf("%ld",&num);
    for (long int i=num;i>0;i-=1)
    {   wrong=0;
        for (int j = 2; j < sqrt(i); j+=1)
        {
            if(i%j==0)
            {
                wrong=1;
                break;
            }
        }
        if (wrong==0)
        { printf("The max prime number is %ld.\n",i);
            break;}
    }
}