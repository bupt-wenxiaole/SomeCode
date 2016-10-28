#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<string> generateGrayCode(int n)
    {
        vector<string> res;
        res.push_back(string("0"));
        res.push_back(string("1"));
        for(int i = 1; i < n; ++i)
        {
            int temp_size = res.size();
            for(int j = 0; j < res.size(); ++j)
            {
                res[j] = '0' + res[j];
            }
            for(int j = temp_size - 1; j >= 0; --j)
            {
                res.push_back('1' + res[j].substr(1, res[j].length()));
            }
        }
        return res;
    }
    
    
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n == 0)
        {
            res.push_back(0);
            return res;
        }
            
        vector<string> str_res = generateGrayCode(n);
        for(auto t : str_res)
        {
            res.push_back((int)bitset<32>(t).to_ulong());
        }
        return res;
    }
    
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> res = s.grayCode(2);
    for(auto t : res)
    {
        cout << bitset<3>(t) << endl; 
    }
    return 0;
}