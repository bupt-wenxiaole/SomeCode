/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        int nextLevel = 0;       //下一层需要访问几个节点
        int tobePrint = 1;      //还需访问几个节点
        queue<TreeLinkNode*> q;
        if(root == NULL)
            return;
        q.push(root);
        while(!q.empty())
        {
            TreeLinkNode* curNode = q.front(); 
            if(curNode -> left != NULL)
            {
                nextLevel++;
                q.push(curNode -> left);
            }
            if(curNode -> right != NULL)
            {
                nextLevel++; 
                q.push(curNode -> right);
            }
            q.pop();
            tobePrint--;
            if(tobePrint == 0) //当前行的最后一个节点
            {
                curNode -> next = NULL;
                tobePrint = nextLevel;
                nextLevel = 0;
            }
            else
            {
                curNode -> next = q.front();
            }
        }
    }
    
};
