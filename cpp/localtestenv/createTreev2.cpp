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

void traversal(TreeNode *node, int len, int &count)
{
    if (!node)
        return;
    count++;
    traversal(node->left, len, count);
    if (count != len)
        cout << node->val << " ";
    else
        cout << node->val;
    traversal(node->right, len, count);
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return left > right ? left + 1 : right + 1;

    }
};


int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {

        vector<int> data;
        while (1)
        {
            int temp;
            cin >> temp;
            data.push_back(temp);
            if (temp == -1)
                break;
        }
        int *data_a = (int *)malloc(sizeof(int) * (data.size() - 1));
        memset(data_a, 0, sizeof(char) * (data.size() - 1));
        for (int i = 0; i < data.size() - 1; i++)
            data_a[i] = data[i];
        TreeNode *tree = NULL;
        tree = constructTree(data_a, data.size() - 1);
        Solution s;
        cout << s.maxDepth(tree) << " ";
        int count = 0;
        traversal(tree, data.size() - 1, count);
        cout << endl;


    }

    return 0;

}