//滑动窗口的最大值
#include <iostream>
#include <deque>
#include <vector>
#include <assert.h>
using namespace std;

vector<int> maxInSlideWindow(const vector<int>& A, int k)
{
    assert (A.size() >= k && k >= 1);
    deque<int> index;  //保存的是有可能是滑动窗口最大值的那些值的下标
    vector<int> res; //保存最后的结果
    for(int i = 0; i < k; i++)
    {
        while(!index.empty() && A[i] >= A[index.back()]) //确保deque当前的队头是最大的
            index.pop_back();
        index.push_back(i);
    }
    for(int i = k; i < A.size(); i++)  //每处理一位(来到一个新的滑窗)，把deque当前的队头压入结果集中保存
    {
        res.push_back(A[index.front()]);
        while(!index.empty() && A[i] >= A[index.back()])     //确保deque当前的队头是最大的
            index.pop_back();
        while(!index.empty() && i - index.front() >= k)       //确保队头在滑窗内
            index.pop_front();
        index.push_back(i);
    }
    res.push_back(A[index.front()]);
    return res;
}

int main(int argc, char const *argv[])
{
    int a[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> A(a, a + sizeof(a) / 4);
    vector<int> res = maxInSlideWindow(A, 3);
    for(auto t : res)
        cout << t << endl;
    return 0;
}