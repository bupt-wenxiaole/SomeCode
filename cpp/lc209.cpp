#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //time complexity : O(n)
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        bool first = true;
        int length = 0, sum = 0, start = 0, end = 0 , res = 0x7fffffff; //res表示最小的连续子数组长度 
        while(start < nums.size() && end < nums.size())
        {
            while(sum < s && end < nums.size())
            {
                sum += nums[end++];
                length ++;
            }
            if(sum < s && end == nums.size() && first) //不存在连续子数组之和>=s return 0
                return 0;
            first = false;
            while(sum >= s && start <= end)
            {
                sum -= nums[start++];
                length --;
                if(sum < s)
                {
                    if(length + 1 < res)
                        res = length + 1;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int test_arr[] = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    vector<int> vi(test_arr, test_arr + sizeof(test_arr)/4);
    Solution s;
    cout << s.minSubArrayLen(80, vi) << endl;

    return 0;
}