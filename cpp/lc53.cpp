class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *dp = new int[nums.size()];
        memset(dp, 0 , sizeof(int) * nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for(int i = 0; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > result)
                result = dp[i];
        }
        delete[] dp;
        return result;
        
        
    }
};