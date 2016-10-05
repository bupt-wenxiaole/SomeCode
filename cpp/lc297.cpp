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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




int main(int argc, char *argv[])
{
    Codec cd;
    string test1("[1]");
    TreeNode* test1_tree = cd.deserialize(test1);
    string test1_str = cd.serialize(test1_tree);
    cout << test1_str << endl;
    

}
