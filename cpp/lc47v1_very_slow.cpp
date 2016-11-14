class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        set<vector<int> > result;
        vector<pair<int, int> > same_mem;
        helper(0, nums.size() - 1, nums, result, same_mem);
        return vector<vector<int> >(result.begin(), result.end());
    }
    bool findPair(const vector<pair<int, int> >&mem, int pos1, int pos2)
    {
        for(int i = 0; i < mem.size(); ++i)
        {
            pair<int, int> temp1 = make_pair(pos1, pos2);
            pair<int, int> temp2 = make_pair(pos2, pos1);
            if(mem[i] == temp1 || mem[i] == temp2)
                return true; 
        }
        return false;
    }
    void helper(int pos, int end, vector<int>& nums, set<vector<int> >& res,
                vector<pair<int, int> >& same_mem)
    {
        if(pos == end)
        {
            res.insert(nums);
            return;
        }
        for(int i = pos; i <= end; ++i)
        {
            if(nums[pos] == nums[i] && !findPair(same_mem, pos, i) && pos != i)
            {
                same_mem.push_back(make_pair(pos, i));
                swap(nums[pos], nums[i]);
                helper(pos + 1, end, nums, res, same_mem);
                swap(nums[pos], nums[i]);
            }
            else if(nums[pos] == nums[i] && pos == i)
            {
                swap(nums[pos], nums[i]);
                helper(pos + 1, end, nums, res, same_mem);
                swap(nums[pos], nums[i]);
            }
            else if(nums[pos] != nums[i])
            {
                swap(nums[pos], nums[i]);
                helper(pos + 1, end, nums, res, same_mem);
                swap(nums[pos], nums[i]);
            }
        }
    }
};
