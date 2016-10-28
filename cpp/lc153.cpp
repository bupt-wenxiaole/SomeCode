class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int min_index = start;
        while(nums[start] > nums[end])
        {
            if(end - start == 1)
                return nums[end];
            min_index = (start + end) / 2; 
            if(nums[min_index] > nums[start])
                start = min_index;
            else if(nums[min_index] < nums[end])
                end = min_index;
        }
        return nums[min_index];
    }
};