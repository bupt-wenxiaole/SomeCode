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
    void helper(TreeNode* root, vector<int>& path, vector<string>& result)
    {
        if(root == NULL)
            return; 
        path.push_back(root -> val);
        if(root -> left == NULL && root -> right ==NULL)
        {
            string temp;
            for(int i = 0; i < path.size() - 1; i++)
                temp += to_string(path[i]) + "->";
            temp += to_string(path[path.size() - 1]);
            result.push_back(temp);
            
        }
        helper(root -> left, path, result);
        helper(root -> right, path, result);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;        
        helper(root, path, res);
        return res;
    }
    
};