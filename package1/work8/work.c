#include <stdio.h>
int main(){
    int a,b,c,d,counter=0,num;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int dm=0;dm<6;dm++){
        for(int cm=0;cm<5-dm;cm++){
            for(int bm=0;bm<5-cm-dm;bm++){
                for(int am=0;am<5-bm-cm-dm;am++){
                    counter+=1;
                    num+=a;
                }
                if(bm==0)num=b;
                else num+=b;
            }
            if(cm==0)num=c;
            else num+=c;
        }
        if(dm==0)num=d;
        else num+=d;
    }
}