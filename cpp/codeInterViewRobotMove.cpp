//RobotMove

#include <iostream>
#include <vector>
using namespace std;

int sumdigit(int n)
{
    int res = 0;
    while(n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
bool check(int threshold, int i, int j, int rows, int cols, vector<vector<bool> >& visit)
{
    if(i >= 0 && i <= rows && j >= 0 && j <= cols && sumdigit(i) + sumdigit(j) <= threshold && visit[i][j] != true)
        return true;
    return false;
}
int movingCountCore(int threshold, int i, int j, int rows, int cols, vector<vector<bool> >& visit)
{
    int count = 0;
    if(check(threshold, i, j, rows, cols , visit))
    {
        visit[i][j] = true;
        count = 1 + movingCountCore(threshold, i - 1, j, rows, cols, visit)
                  + movingCountCore(threshold, i + 1, j, rows, cols, visit)
                  + movingCountCore(threshold, i, j + 1, rows, cols, visit)
                  + movingCountCore(threshold, i, j - 1, rows, cols, visit);
    }
    return count;

}

int movingCount(int threshold, int rows, int cols)
{
    vector<vector<bool> > visit(rows, vector<bool>(cols, false));
    int count = movingCountCore(threshold, 0, 0, rows, cols, visit);
    return count;
}






int main(int argc, char const *argv[])
{
    int res = movingCount(2, 3, 3);
    cout << res << endl;
    return 0;
}