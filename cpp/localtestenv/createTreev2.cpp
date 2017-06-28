/**************************************************************
this version is used for testing leetcode's binary problem in
local environment which  the input data include double
digits or more
****************************************************************/


#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {} ;
};

TreeNode *constructTree(int *dat , int len)
{
    TreeNode *root = NULL;
    int index = 0;
    if (len > 0)
        root = new TreeNode(dat[index]);
    else
        return NULL;

    list<TreeNode *> node;
    node.push_back(root);
    index ++;
    while (index < len)
    {
        if (!node.empty())
        {
            TreeNode *root = node.front();
            if (index < len )
            {
                if (dat[index] != 0)
                {
                    root->left = new TreeNode(dat[index]);
                    node.push_back(root->left);
                }
                index ++;
            }
            if (index < len )
            {
                if (dat[index] != 0)
                {
                    root->right = new TreeNode(dat[index]);
                    node.push_back(root->right);
                }
                index ++;
            }
            node.pop_front();
        }
    }

    return root;
}

class Solution {
public:
    void helper(TreeNode* t1, TreeNode* t2, TreeNode** child) {
        *child = NULL;
        if(t1 == NULL && t2 == NULL)
            return;
        if(t1 == NULL && t2 != NULL) {
            cout << t2 -> val << endl;
            t1 = new TreeNode(t2 -> val);
            *child = t1; //保存这个孩子
            return;
        }
        if(t1 != NULL && t2 == NULL) 
            return;
        if(t1 != NULL && t2 != NULL)
            t1 -> val += t2 -> val;
        helper(t1 -> left, t2 -> left, child);
        if(*child != NULL)
            t1 -> left = *child;
        helper(t1 -> right, t2 -> right, child);
        if(*child != NULL)
            t1 -> right = *child;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* c = NULL;
        helper(t1, t2, &c);
        return t1;
    }
};

int main(int argc, char *argv[])
{
    int data_a[] = {1, 3, 2, 5};
    int data_b[] = {2, 1, 3, 0, 4, 0, 7};
    TreeNode* tree1 = constructTree(data_a, sizeof(data_a)/sizeof(data_a[0]));
    TreeNode* tree2 = constructTree(data_b, sizeof(data_b)/sizeof(data_b[0]));
    Solution s;
    TreeNode* result = s.mergeTrees(tree1, tree2);
    return 0;

}
