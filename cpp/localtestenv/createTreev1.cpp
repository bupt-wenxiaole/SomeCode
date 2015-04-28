/***********************************************************
this version is used for testing leetcode's binary problem in
local environment which  the input data only include the
single-digit number
*************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <time.h>
using namespace std;

struct TreeNode
{
	int	val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val):val(val), left(NULL),right(NULL){} ; 
};

TreeNode *constructTree(char *dat , int len)
{
	TreeNode *root = NULL;
	int index = 0;
	if(len > 0)
		root = new TreeNode(dat[index] - '0');
	else
		return NULL;

	list<TreeNode *> node;
	node.push_back(root);
	index ++;
	while(index < len)
	{
		if(!node.empty())
		{
			TreeNode *root = node.front();
			if(index < len )
			{
				if(dat[index] != '#')
				{
					root->left = new TreeNode(dat[index] - '0');	
					node.push_back(root->left);
				}
				index ++;
			}
			if(index < len )
			{
				if(dat[index] != '#')
				{
					root->right = new TreeNode(dat[index] - '0');	
					node.push_back(root->right);
				}
				index ++;
			}
			node.pop_front();
		}
	}

	return root;
}
//please paste your leetcode binarytree problem's code below 

class Solution {
public:
    bool isSymmetric(TreeNode *root) 
    {
        if ((root==NULL) || (root->left==NULL && root->right==NULL))
            return true;
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode *left,TreeNode *right)
    {
        if (left==NULL && right==NULL)
            return true;
        if ((left==NULL) || (right==NULL) || (left->val != right->val))
            return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
};


int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout <<"Usage: ./createTreev1 1223443"<<endl;x
		exit(1);
	}

	string treeinfo = argv[1];
	if(treeinfo.size() < 1)
	{
		cout <<"tree data invalid"<<endl;
		exit(1);
	}
	int len = treeinfo.size();
	char *dat = new char[len];
	for(int i=0; i<len; i++)
	{
		dat[i] = treeinfo[i];	
	}
	for(int i=0; i<len; i++)
		cout << "\t"<<dat[i] ;
	cout << endl;

	TreeNode *root = NULL;
	root = constructTree(dat, len);

	Solution s;
	bool result = s.isSymmetric(root);   //modify this line code to keep same with the  function above
	cout << result;
	cout << endl;
	cout << endl;

	delete dat;
}