//寻找指定路径是否存在 DFS
#include <vector>
#include <iostream>
using namespace std;

bool helper(const vector<vector<char> >& matrix, int i, int j, int& curstrlength, vector<vector<bool> >& visit, const string& path)
{
    if(curstrlength == path.size())
        return true;
    bool flag = false;
    if( i >= 0 && i < matrix.size() 
        && j >= 0 && j < matrix[0].size()
        && matrix[i][j] == path[curstrlength]
        && visit[i][j] != true)
    {
        curstrlength++;
        visit[i][j] = true;
        flag = helper(matrix, i + 1, j, curstrlength, visit, path) || 
               helper(matrix, i - 1, j, curstrlength, visit, path) ||
               helper(matrix, i, j - 1, curstrlength, visit, path) ||
               helper(matrix, i, j + 1, curstrlength, visit, path);
        if(!flag)
        {
            curstrlength--;
            visit[i][j] = false;
        }
    }
    
    return flag;
}
bool hasPath(const vector<vector<char> >& matrix, const string& path)
{
    vector<vector<bool> > visit(matrix.size(), vector<bool> (matrix[0].size(), false));
    int curstrlength = 0;
    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix.size(); ++j)
        {
            curstrlength = 0;
            if(helper(matrix, i, j, curstrlength, visit, path))
                return true;
        }   
    }
    return false;
}




int main(int argc, char const *argv[])
{
    vector<vector<char> > matrix(3, vector<char> (4, '#'));
    bool first = true;    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < 3; ++i)
    {
        first = true;
        for(int j = 0; j < 4; ++j)
        {
            if(first)
            {
                cout << matrix[i][j];
                first = false;
            }
            else
                cout << " " << matrix[i][j];

        }
        cout << '\n';

    }
    string path1("bcced");
    string path2("abcb"); 
    cout << hasPath(matrix, path1) << endl;
    cout << hasPath(matrix, path2) << endl;
    return 0;
}