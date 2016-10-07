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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        helper(&root, inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
    void helper(TreeNode** root, vector<int>& inorder, vector<int>& postorder, 
                int in_start, int in_end, int post_start, int post_end)
    {
        if(in_start > in_end || post_start > post_end)
            return;
        int root_val = postorder[post_end];
        *root = new TreeNode(root_val);
        int root_pos = -1;
        for(int i = in_start; i <= in_end; i++)
        {
            if(inorder[i] == root_val)
                root_pos = i;
        }
        int in_start_left = in_start;
        int in_end_left = root_pos - 1;
        int in_start_right = root_pos + 1;
        int in_end_right = in_end;
        int post_start_left = post_start;
        int post_end_left = post_start + (in_end_left - in_start_left);
        int post_start_right = post_start + (in_end_left - in_start_left + 1);
        int post_end_right = post_end  - 1;
        helper(&((*root) -> left), inorder, postorder, in_start_left, in_end_left, post_start_left, post_end_left);
        helper(&((*root) -> right),inorder, postorder, in_start_right, in_end_right, post_start_right, post_end_right);
    }
};