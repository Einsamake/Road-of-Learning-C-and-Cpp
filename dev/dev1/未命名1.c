#include <stdio.h>

int array[100];

int game(int n, int  start , int target)            //递归大家做游戏
{   
                                       //n:小孩总数， start ：从下标为  start  的小孩开始报数，target:报数值
    int i,current=0, count = 0, g;             // current:当前报数值
    do
    {	
        
        if(array[start]!=0)                           //报数小孩不能为空
        {
            current++;
            if( current == target ){
				array[ start ] = 0;                     //该小孩退出队                             //报数
            	break; 
			}
			start = (start + 1) % n;                         //报数到退出值
                                      //循环到队首
        }
        else{
        	while( array[ start ] == 0 )           //跳过已出队者
            {
                start = (start + 1) % n;
            }
		}
    }while(  1 );                         //报数一次，退出一个小孩
    for(i=0;i<n;i++)                       //统计还在队内的小孩个数
        if(array[i]!=0)
        {
            g=i;
            count++;
        }
    if( count == 1 )                        //剩一个小孩结束递归
        return(g+1);                             //返回队中最后一人编号
    while(array[ start ]==0)                        //计算下次开始报数小孩
    {
        start = (start + 1) % n;
    }
    return(game(n, start ,target));                 //递归调用报数函数
}

int main()
{
    int i,n,target;
    scanf("%d%d",&n,&target);                                    //输入小孩总数，报数值    
    for(i=0;i<n;i++)
        array[i]=i+1;
                                                      //给小孩编号
    printf("The left child is NO %d.\n",game(n,0,target)); //从第一个小孩开始报数
    return 0;
}

