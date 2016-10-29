class Solution {
public:
    Solution(vector<int> nums) {
        nums_start.assign(nums.begin(), nums.end());
        real_nums.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        real_nums.assign(nums_start.begin(), nums_start.end()); 
        return real_nums;
    }
    int generateRandomIndex(int start, int end)
    {
        return start + rand() %  (end - start + 1);
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        reset();
        for(int i = 0; i < real_nums.size(); ++i)
        {
            int index = generateRandomIndex(i, real_nums.size() - 1);
            swap(real_nums[i], real_nums[index]);
        }
        return real_nums;
    }
private:
    vector<int> nums_start;
    vector<int> real_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

