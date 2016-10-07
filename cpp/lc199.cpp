/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int max_depth  = 0;
        int cur_depth = 0;
        vector<int> res; 
        helper(root, cur_depth, max_depth, res);
        return res;
    }
    void helper(TreeNode* root, int& cur_depth, int& max_depth, vector<int>& res)
    {
        if(root == NULL)
            return;
        cur_depth++;
        if(max_depth < cur_depth)
        {
            res.push_back(root -> val);
            max_depth = cur_depth;
        }
        helper(root -> right, cur_depth, max_depth, res);
        helper(root -> left, cur_depth, max_depth, res);
        cur_depth--;
        
    }
};