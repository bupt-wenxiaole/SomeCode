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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL || (root != NULL && root -> left == NULL && root -> right == NULL))
            return 0; 
        int res = 0;
        helper(root -> left, true, res);
        helper(root -> right, false, res);
        return res;
    }
    void helper(TreeNode* root, bool left, int& res)
    {
        if(root == NULL)
            return; 
        if(root != NULL && root -> left == NULL && root -> right == NULL && left == true)
            res += root -> val;
        helper(root -> left, true, res);
        helper(root -> right, false, res);
        
    }
};