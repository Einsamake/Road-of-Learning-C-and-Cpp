#include <stdio.h>

typedef struct buy
{  char  gname;  /* 商品名称 */
    int   sname;  /* 商店名称 */
    int   gprice;  /* 商品价格 */
} BUY;
int main( )
{  int i, j, n;
    int min, price[10][3];
    int findm( int n, int price[][3], BUY scheme[] );
    static BUY scheme[3]={
        {'A', 0, 0},
        {'B', 0, 0},
        {'C', 0, 0}
    };
    scanf( "%d", &n );
    for( i = 0; i < n; i++ )
        for( j = 0; j < 3; j++ )
            scanf( "%d", &price[i][j] );

    min = findm( n, price, scheme );
    printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );
    for ( i=0; i < 3; i++ )
        printf("%c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );
    return 0;
}
int findm( int n, int price[][3], BUY scheme[] ) {
    int min[3]={10000,10000,10000},name[3]={-1,-1,-1};
    int cost=0,flag=0;
    for (int i=0; i < 3; i++) {         //商品
        for (int j=0; j < n; j++) {       //店
            for (int k=0; k < 3; k++) {
                if (j==name[k]) {
                    flag=1;
                    break;
                }
            }
            if (min[i]>price[j][i]&&flag==0) {
                min[i]=price[j][i];
                name[i]=j;
            }
            flag=0;
        }
        scheme[i].sname=name[i]+1;
        scheme[i].gprice=min[i];
        cost+=scheme[i].gprice;
    }
    return cost;
}//
// Created by Lenovo on 2025/12/23.
//