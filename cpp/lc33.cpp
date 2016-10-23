class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target)  //
    {
        if(start > end)
            return -1;
        int mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target)
            return binary_search(nums, start, mid - 1, target);
        else
            return binary_search(nums, mid + 1, end, target);
            
    }
    int findTheSmallInRotate(vector<int>& nums, int start, int end)
    {
        int index1 = start;
        int index2 = end;
        int midIndex = start;
        while(nums[index1] > nums[index2])
        {
            if(index2 - index1 == 1)
            {
                midIndex = index2; 
                break;
            }
            midIndex = (index1 + index2) / 2;
            if(nums[midIndex] >= nums[index1])
                index1 = midIndex;
            else if(nums[midIndex] <= nums[index2])
                index2 = midIndex;
            
        }
        return midIndex;
    }
    int search(vector<int>& nums, int target) {
        int small_index = findTheSmallInRotate(nums, 0, nums.size() - 1);
        if(small_index == 0)  //整个数组有序，直接二分查找
            return binary_search(nums, 0, nums.size() -1, target);
        int result = binary_search(nums, 0, small_index - 1, target); //二分前半段
        if(result != -1)
            return result;
        return binary_search(nums, small_index, nums.size() - 1, target);
        }
};