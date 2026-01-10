#include <stdio.h>

int main()
{
    int min,max,one,ten,hun,thou,counter;
    while (1)
    {
        counter=0;
        scanf("%d%d",&min,&max);
        if (min>=1000&&max>=1000&&max>=min){
            for(int i=min;i<=max;i++){
                if(i%2==0){
                    thou=i/1000;
                    hun=i/100%10;
                    one=i%10;
                    ten=i/10%10;
                    if(!(one==ten||one==hun||one==thou||ten==hun||ten==thou||hun==thou)){
                        printf("%d  ",i);
                        counter++;
                    }
                }
            }
            printf("\n");
            printf("counter=%d\n",counter);
        } else if(max==0&&min==0) { break;}
        else printf("Error\n");
    }
}