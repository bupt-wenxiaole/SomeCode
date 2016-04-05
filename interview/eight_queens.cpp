/**********************************************************************
@八皇后问题：回溯法，逐列进行深度优先搜索，即循环中递归
@不用二维数组，因为一行中只能放置一个皇后，一维即可，c[cur]表示第cur行中皇后在第c[cur]列
@xiaolewen_bupt
@2016/04/05
************************************************************************/


#include <stdio.h>
#include <iostream>
using namespace std;
#define N 8  //八皇后问题，8*8的棋盘中放置8个皇后，皇后无法互相攻击，共有多少种方案，高斯认为72种，计算机发明后编程得知为92种
int c[N]={0};
int tot=0;   
void search(int cur)  //cur 表示当前是哪一行，要得到最后的结果传0进去,即search(0)
{
    if(cur == N)
    {
        tot++;
        //printf("第%d种方案*******************\n", tot);      //是否打印方案
        //for(int i=0;i<N;i++)
        //{
        //    for(int j=0;j<N;j++)
        //    {
        //        if(c[i]==j)
        //            printf("0 ");
        //        else
        //            printf("* ");
//
        //    }
        //    printf("\n");
        //}
    

    }

    else
    {
         for(int i=0;i<N;i++)   //i表示列
        {
            bool ok=true;
            c[cur]=i;      //尝试把当前行的皇后放在第i列上
            for(int j=0;j<cur;j++)  //查看是否可以互相攻击
            {
                if(c[cur]==c[j] || cur-c[cur]==j-c[j] || cur+c[cur]==j+c[j])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
                search(cur+1);
        }

    }
   
}



int main(int argc, char const *argv[])
{
    search(0);
    printf("%d\n",tot);
    return 0;
}

