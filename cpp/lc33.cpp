class Solution {
//注意题意，这道题的旋转就是拿前面K个元素放在后面，和其他那些右移K步（K可以无限大）的不一样。
//思路：先用二分的方法找到旋转数组中的最小值，（之后在前后两个部分利用二分）利用一个指针指在前半部分，另外一个指针指向后半部分，当两个指针相邻时，后一个指针指向的就是旋转数组的最小值, 但是这个地方需要注意两个点，首先，有序数组本身也算一种旋转，这时
//直接返回start，还有一种就是start, mid ,end 相等(无法判断mid属于哪个部分)的情况，顺序查找最小值
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
    int sequenceSearch(vector<int>& nums)
    {
        int min = 0x7fffffff;
        int min_index = 0;
        for(int i = 0;i < nums.size(); ++i)
        {
            if(nums[i] < min)
            {
                min = nums[i];
                min_index = i;
            }
                
        }
        return min_index;
    }
    int findTheSmallInRotate(vector<int>& nums, int start, int end)
    {
        int index1 = start;
        int index2 = end;
        int midIndex = start;
        while(nums[index1] >= nums[index2])
        {
            if(index2 - index1 == 1)
            {
                midIndex = index2; 
                break;
            }
            midIndex = (index1 + index2) / 2; 
            if(nums[index1] == nums[midIndex] && nums[midIndex] == nums[index2])
                return sequenceSearch(nums);
            if(nums[midIndex] >= nums[index1])
                index1 = midIndex;
            else if(nums[midIndex] <= nums[index2])
                index2 = midIndex;
            
        }
        return midIndex;
    }
    
    int search(vector<int>& nums, int target) {
        int small_index = findTheSmallInRotate(nums, 0, nums.size() - 1);
        cout << small_index;
        if(small_index == 0)  //整个数组有序，直接二分查找
            return binary_search(nums, 0, nums.size() -1, target);
        int result = binary_search(nums, 0, small_index - 1, target); //二分前半段
        if(result != -1)
            return result;
        return binary_search(nums, small_index, nums.size() - 1, target);
        
        
        
    }
};