class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                count++;
                if(count >= 3)
                    continue;
            }
            else
                count = 1;
            nums[index++] = nums[i];
                
        }
        return index;
    }
};