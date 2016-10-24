#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int start, int end) //start, end 表示子树开始和结束的位置
    {
        TreeNode* root = NULL;
        if(((end - start + 1) & 0x1) == 1 && start <= end) //奇数个节点
        {
            int root_index = (start + end) / 2;
            root = new TreeNode(nums[root_index]);
            root -> left = helper(nums, start, root_index - 1);
            root -> right = helper(nums, root_index + 1, end);

        }
        else if (((end - start + 1) & 0x1 )== 0 && start <= end) //偶数个节点
        {
            int root_index  = (start + end) / 2 + 1;
            root = new TreeNode(nums[root_index]);
            root -> left = helper(nums, start, root_index - 1);
            root -> right = helper(nums, root_index + 1, end);
        }
        return root;
    }
};


int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> vi(a, a + sizeof(a) / 4);
    Solution s;
    s.sortedArrayToBST(vi);
    return 0;

}