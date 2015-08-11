/*核心思路：利用深度优先搜索使得在遍历到每个新出现的黑格子（联通区域＋1）时把与其相连的每个格子都标记为已经访问*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5  //nxn的正方形
#define MAXN N+2 //正方形外面加个白圈

int matrix[MAXN][MAXN]={0};
int vis[MAXN][MAXN]={0};  //第一个二维数组记录正方形的黑白格分配情况，第二个二维数组纪录每个单元格的颜色


//memset(matrix,0,sizeof(matrix));
//memset(vis,0,sizeof(vis));   //初始化全部记为白块


void dfs(int x,int y)
{
	if (matrix[x][y]==0 || vis[x][y]==1)  //如果该块被访问过或者是白块，直接返回
		return;
	vis[x][y]=1; //标记该块已经被访问过
	dfs(x-1,y+1);dfs(x,y+1);dfs(x+1,y+1);
	dfs(x-1,y);             dfs(x+1,y);
	dfs(x-1,y-1);dfs(x,y-1);dfs(x+1,y-1);

}


void inputdata()     //通过这个函数来输入黑白块的分配情况
{	char s[N+1];
	
	for(int i=0;i<N;++i)
	{	
		//memset(s,'0',sizeof(s));
		scanf("%s",s);
		getchar();
		for(int j=0;j<N;++j)
		{
			matrix[i+1][j+1]=s[j]-'0';
			//printf("%s",s);

		}
		//printf("%s\n",s);
	}
	return;
}

int main(int argc, char const *argv[])
{
	
	inputdata();
	//printf("aaaa");
	int count=0;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			if(matrix[i][j]==1 && vis[i][j]==0)
			{
				count++;
				dfs(i,j);

			}
		}
	}
	printf("%d\n",count);
	return 0;
}