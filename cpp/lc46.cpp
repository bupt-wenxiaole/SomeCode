class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int begin = 0,  end = nums.size() - 1;
        vector<vector<int>> result;
        permute(nums, begin, end, result);
        return result;
    }
    void permute(vector<int>& nums, int begin, int end, vector<vector<int>>& result)
    {
        if(begin == end)
        {
             result.push_back(nums);
             return;
        }
        for(int i = begin; i <= end; i++)
        {
            swap(nums[begin], nums[i]);
            permute(nums, begin + 1, end, result);
            swap(nums[begin], nums[i]);
        }
    }
};