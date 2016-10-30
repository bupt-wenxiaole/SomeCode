#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

int main(int argc, char const *argv[])
{
    int test_arr[] = {2, 1};
    Solution s;
    vector<int> vi(test_arr, test_arr + 2); 
    cout << s.findKthLargest(vi, 2);
    return 0;
}