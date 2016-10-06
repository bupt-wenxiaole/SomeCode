/**************************************************************
this version is used for testing leetcode's binary problem in
local environment which  the input data include double
digits or more
****************************************************************/


#include <cstdio>
#include <cstdlib>
#include <stack>
#include <sstream>
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
#include <deque>
#include <cassert>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {} ;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize_helper(root, res);   //实际的序列化二叉树
        res = '[' + res;
        assert(res[res.length() - 1] == ',');
        res[res.length() - 1] = ']';                     
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        data = data.substr(1, data.length() - 2);
        istringstream ss(data);
        string token;
        deque<string> res;
        while(std::getline(ss, token, ','))
        {
            res.push_back(token);
        }
        deserialize(&root, res);
        return root;
    }
private:
    void serialize_helper(TreeNode* root, string& res)
    {
        if(root == NULL)
        {
            res += "null,";
            return;
        }
        res += (to_string(root -> val) + ',');
        serialize_helper(root -> left, res);
        serialize_helper(root -> right, res); 
    }
    void deserialize(TreeNode** root, deque<string>& res)
    {
        if(!res.empty() && res.front() != "null")
        {
            int val = stoi(res.front());
            *root = new TreeNode(val);
            res.pop_front();
            deserialize(&((*root) -> left), res);
            deserialize(&((*root) -> right), res);

        }
        else if(!res.empty() && res.front() == "null")
            res.pop_front();

    }
    
};
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> curlevel; 
        vector<vector<int> > res;
        int tobeprinted = 1;   //tobeprinted 和 nextlevel 用于标记换行
        int nextlevel = 0;
        int levelnum = 1; //用于指示当前的行号，从1开始
        if(root == NULL)
            return res;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            if((levelnum & 0x1) == 1)
            {
                if(!s1.empty())
                {
                    if(s1.top() != NULL)
                    {
                        curlevel.push_back(s1.top() -> val);
                        if(s1.top() -> left != NULL)
                        {
                            s2.push(s1.top() -> left);
                            nextlevel++;
                        }
                       
                        if(s1.top() -> right != NULL)
                        {
                            s2.push(s1.top() -> right);
                            nextlevel++;
                        }
                        s1.pop();

                    }
                    
                }
            }
            else
            {
                if(!s2.empty())
                {
                    if(s2.top() != NULL)
                    {
                        curlevel.push_back(s2.top() -> val);
                        if(s2.top() -> right != NULL)
                        {
                            s1.push(s2.top() -> right);
                            nextlevel++;
                        }
                       
                        if(s2.top() -> left != NULL)
                        {
                            s1.push(s2.top() -> left);
                            nextlevel++;
                        }
                        s2.pop(); 

                    }
                       
                        
                }
            }
            tobeprinted--;
            if(tobeprinted == 0)
            {
                res.push_back(curlevel);
                curlevel.clear();
                tobeprinted = nextlevel;
                nextlevel = 0;
                levelnum++;
            }
        }
        return res;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




int main(int argc, char *argv[])
{
    Codec cd;
    string test1("[1,2,4,null,null,null,3,null,5,null,null]");
    TreeNode* test1_tree = cd.deserialize(test1);
    Solution s;
    vector<vector<int> > res = s.zigzagLevelOrder(test1_tree);
    for(auto i : res)
        for(auto j : i)
        {
            cout << j << endl;
        }

}
