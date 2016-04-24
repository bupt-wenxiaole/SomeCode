/***************************************************
@xiaole_wen_bupt
@输入一个n*n的黑白图像（1代表黑色，0代表白色)
@统计出其中八连块的个数
@如果两个黑格子有公共边或者有公共顶点，就说它们属于同一个八连块
******************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int mat[MAXN][MAXN];
int vis[MAXN][MAXN]; 


void dfs(int x,int y)   //从每个格子出发，递归的访问它所有的相邻黑格子 
{
    if(!mat[x][y] || vis[x][y])
        return;
    vis[x][y]=1;
    dfs(x-1,y-1);
    dfs(x-1,y);
    dfs(x-1,y+1);
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x+1,y+1);
    dfs(x+1,y-1);
}

int main(int argc, char const *argv[])
{
    int n;
    char s[MAXN];
    while(scanf("%d",&n))
    {
        memset(mat,0,sizeof(mat));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i)
        {
            scanf("%s",s);
            for(int j=0;j<n;++j)
            {
                mat[i+1][j+1]=s[j]-'0';
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mat[i][j] && !vis[i][j])
                {
                    count++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}


