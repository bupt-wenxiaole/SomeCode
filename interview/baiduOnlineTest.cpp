#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


void dfs(int i, int j, int **mat, int **vis,int &count,int &flag)
{
    if(mat[i][j] == 0|| vis[i][j])
        return;
    vis[i][j] = flag;

    dfs(i - 1, j, mat, vis,count,flag);
    dfs(i + 1, j, mat, vis,count,flag);
    dfs(i , j - 1, mat, vis,count,flag);
    dfs(i , j + 1, mat, vis,count,flag);
    if((mat[i-1][j-1] == 1 && vis[i-1][j-1]!=flag) || (mat[i+1][j+1] == 1 && vis[i+1][j+1]!=flag) 
        ||(mat[i-1][j+1] == 1 && vis[i-1][j+1]!=flag) || (mat[i+1][j-1] && vis[i+1][j-1]!=flag))
        count--;
}
int beautiful(int **grid, int n, int m)
{
    int count = 0;
    int flag = 0;
    int **mat = new int*[n+5];
    for(int i = 0; i < n+5; i++)
        mat[i] = new int[m+5];
    for(int i =0; i < n+5; i++)
    {
        for(int j=0; j<m+5; j++)
            mat[i][j] = 0;
    }
    int **vis = new int*[n+5];
    for(int i = 0; i < n+5; i++)
        vis[i] = new int[m+5];
    for(int i =0; i < n+5; i++)
    {
        for(int j=0; j<m+5; j++)
            vis[i][j] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            mat[i][j] = grid[i - 1][j - 1];
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(mat[i][j] && vis[i][j] == 0)
            {
                count++;
                flag ++;
                dfs(i, j, mat, vis, count, flag);
                
            }
        }
    }
    delete[] mat;
    delete[] vis;
    return count;
    

}

int main(int argc, char const *argv[])
{
    int **p = new int*[5];
    for(int i = 0; i < 5; i++)
        p[i] = new int[5];
    char s[100];
    for(int i=0; i < 5; i++)
    {
        scanf("%s",s);
        for(int j=0; j<5; j++)
            p[i][j] = s[j] - '0';
    }
    int result = beautiful(p,5,5);
    cout << result << endl;
    return 0;
}