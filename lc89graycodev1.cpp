#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;
class Solution {
public:
    int mostRightOneIndex(int num) //求一个数的二进制中最右边的1的出现在哪一位上
    {
        int x = 0x1;
        int index = 0;
        while(num)
        {
            if((num & 0x1) == 0x1)
            {
                return index;
            }
            else
            {
                num = num >> 1;
                index++;
            }
        }
        return -1; 
    }
    
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n == 0)
            return res;
        bool flag = true; //用来指示变换规则
        for(int i = 1; i < pow(2, n); ++i)
        {
            if(flag)  //最右边bit取反
            {
                res.push_back(res.back() ^ 0x1);
                flag = false;
            }
            else //最右边的1的左边bit位取反
            {
                int last_num = res.back();
                int index = mostRightOneIndex(last_num);
                last_num ^= (1 << (index + 1));
                res.push_back(last_num);
                flag = true;
            }
            
        }
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> res = s.grayCode(3);
    for(auto t : res)
    {
        cout << bitset<3>(t) << endl; 
    }
    return 0;
}