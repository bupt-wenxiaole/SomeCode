class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = 0x80000000;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > res)
                res = nums[i];
        }
        vector<int> local_max_positive_num(n, 0); //l_m_p[i]表示以nums[i - 1]结尾的连续子数组的最大正乘积,最后的结果从这些值中取出全局最大
        vector<int> local_min_negative_num(n, 0); //l_m_n[i]表示以nums[i - 1]结尾的连续子数组的最小负乘积
        if(nums[0] > 0)
            local_max_positive_num[0] = nums[0];
        else if(nums[0] < 0)
            local_min_negative_num[0] = nums[0];
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > 0)
            {
                local_max_positive_num[i] = max(local_max_positive_num[i - 1] * nums[i], nums[i]);
                local_min_negative_num[i] = local_min_negative_num[i - 1] * nums[i];
            }
            else if(nums[i] < 0)
            {
                local_max_positive_num[i] = local_min_negative_num[i - 1] * nums[i];
                local_min_negative_num[i] = min(local_max_positive_num[i - 1] * nums[i], nums[i]);
            }
            if(local_max_positive_num[i] > res)
                res = local_max_positive_num[i];
                
        }
        return res;
    }
        
};