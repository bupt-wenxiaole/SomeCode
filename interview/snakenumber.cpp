/**********************************************************
@蛇形填数:首先试探下一个位置能不能填，能填的话就填上，否则更换填数方向
@xiaolewen_bupt
@2016／04／03
注意这一点：数组大小不能用变量来开，这不符合c/c++的规范
比如 int n=10; int a[n];  这种写法会导致未知的错误
***********************************************************/


#include <iostream>
using namespace std;
#define N 20

int matrix[N][N];
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n)
    {
        memset(matrix,0,sizeof(matrix));

        int x=0,y=0,tot=1;  //填数的位置的两个下标和待填入的数字
        matrix[0][0]=tot;
        while(tot<n*n)
        {
            while (matrix[x][y+1]==0 && y+1<n)   { matrix[x][++y] = ++tot; }     //控制条件有两个，不能超出范围并且不能填已经填过的
            while (matrix[x+1][y]==0 && x+1<n)   { matrix[++x][y] = ++tot; }
            while (matrix[x][y-1]==0 && y-1>=0)  { matrix[x][--y] = ++tot; }
            while (matrix[x-1][y]==0 && x-1>=0)  { matrix[--x][y] = ++tot; }
        }
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}

