class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i =  0, j = 0, current_color = 0;
        while(j < nums.size())
        {
            while(current_color < 3)
            {
                for(; i < nums.size(); i++)
                {
                    if(nums[i] == current_color)
                    {
                        swap(nums[i], nums[j]);
                        j++;
                    }
                }
                i = j;
                current_color++;
                
            }
            
        }
    }
};