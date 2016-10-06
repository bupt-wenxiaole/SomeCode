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
    vector<vector<int> > levelOrder(TreeNode* root)
    {
        int nextlevel = 0;
        int tobeprinted = 1;
        vector<int> curlevel;
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            curlevel.push_back(q.front() -> val);
            if(q.front() -> left != NULL)
            {
                q.push(q.front() -> left);
                nextlevel++;
                
            }
            if(q.front() -> right != NULL)
            {
                q.push(q.front() -> right);
                nextlevel++;
            }
            q.pop();
            tobeprinted--;
            if(tobeprinted == 0)
            {
                res.push_back(curlevel);
                curlevel.clear();
                tobeprinted = nextlevel;
                nextlevel = 0;
            }
            
        }
        return res;
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<vector<int> > levelorder_res;
        if(root == NULL)
            return res;
        levelorder_res = levelOrder(root);
        for(auto t : levelorder_res)
            res.push_back(t[t.size() - 1]);
        return res;
        
    }
};