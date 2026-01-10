#include "stdio.h"
typedef struct cord{
    int x;
    int y;
}cord;
long long jie(int m){
    if(m<=1)return 1;
    else return m*jie(m-1);
}
long long jie1(int m,int n) {
    int sum=1;
    for (;m>n;m--) {
        sum*=m;
    }
    return sum;
}
long long comb_divide_early(int n, int k) {
    if (k > n - k) k = n - k;
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;  // 先乘后除，但保证能整除
    }
    return result;
}
int c(int m,int n){
    if (n>m/2)n=m-n;
    return jie1(m,n)/jie(n);
}
int main(){
    cord mid,final;
    scanf("%d%d",&final.x,&final.y);
    scanf("%d%d",&mid.x,&mid.y);
    long long sum1=comb_divide_early(mid.x+mid.y,mid.x);
    long long sum2=comb_divide_early(final.x-mid.x+final.y-mid.y,final.x-mid.x);

    printf("%lld\n",sum1*sum2);
    for(int i=0;i<mid.x;i++){
        printf("(%d,0)",i);
    }
    for(int i=0;i<mid.y;i++){
        printf("(%d,%d)",mid.x,i);
    }
    printf("(%d,%d)",mid.x,mid.y);
    for(int i=mid.x+1;i<=final.x;i++){
        printf("(%d,%d)",i,mid.y);
    }
    for(int i=mid.y+1;i<=final.y;i++){
        printf("(%d,%d)",final.x,i);
    }
    printf("\n");

}