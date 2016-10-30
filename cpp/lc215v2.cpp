class Solution {
public:
    int generateRandomIndex(int start, int end)
    {
        return start + rand() % (end - start + 1);
    }
    
    int partion(vector<int> &nums, int start, int end)
    {
        int pos = generateRandomIndex(start, end);
        swap(nums[pos], nums[end]);
        int small = start - 1;
        for(int i = start; i < end; ++i)
        {
            
            if(nums[i] < nums[end])
            {
                small++;
                if(small != i)
                    swap(nums[i], nums[small]);
            }
        }
        small++;
        swap(nums[small], nums[end]);
        return small;
    }
    int helper(vector<int>& nums, int k, int start, int end)
    {
        int pos = partion(nums, start, end);
        if(nums.size() - pos == k)
            return nums[pos];
        else if(nums.size() - pos > k)
            return helper(nums, k, pos + 1, end);
        else
            return helper(nums, k, start, pos - 1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, k, 0, nums.size() - 1);
    }
};