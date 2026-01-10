#include <stdio.h>
#define N 3
int current[N],k=0;
double maxarea=0;
double square(int ,int ,int ,int);

void dfs(int depth,int start,int x[],int y[],int n){
    if(depth==3){
        int x1,x2,y1,y2;
        x1=x[current[1]]-x[current[0]];x2=x[current[2]]-x[current[0]];
        y1=y[current[1]]-y[current[0]];y2=y[current[2]]-y[current[0]];
        double area=square(x1,y1,x2,y2);
        if (area>maxarea){
            maxarea=area;
        }
    } else{
        for (int i = start; i < n; ++i) {
            current[depth]=i;
            dfs(depth+1,i+1,x,y,n);
        }
    }
}
double square(int x1,int y1,int x2,int y2){
    double sq;
    sq=(x1*y2-x2*y1)/2.;
    return (sq<0)?-sq:sq;
}
void work(){
    maxarea=0;
    int n;
    scanf("%d", &n);
    int x[n],y[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&x[i],&y[i]);
    }
    dfs(0,0,x,y,n);
    printf("%.1lf\n",maxarea);
}
int main() {
    int n1;
    scanf("%d",&n1);
    for (int i = 0; i < n1; ++i) {
        work();
    }
}/*
223 872
-161 324
-967 -770
-392 -165
-755 -184
725 226
360 275
-96 -896
-984 -45
941 -669
692 -347
100 -92
797 165
658 878
-972 498
108 128
-516 895
661 -175
 */
