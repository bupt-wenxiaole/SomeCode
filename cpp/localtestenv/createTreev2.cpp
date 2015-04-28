/**************************************************************
this version is used for testing leetcode's binary problem in
local environment which  the input data include double 
digits or more
****************************************************************/ 


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
#include <string.h>
using namespace std;

struct TreeNode
{
	int	val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val):val(val), left(NULL),right(NULL){} ; 
};

TreeNode *constructTree(int *dat , int len)
{
	TreeNode *root = NULL;
	int index = 0;
	if(len > 0)
		root = new TreeNode(dat[index]);
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
					root->left = new TreeNode(dat[index]);	
					node.push_back(root->left);
				}
				index ++;
			}
			if(index < len )
			{
				if(dat[index] != '#')
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

void traversal(TreeNode *node)
{
	if(!node)
		return;
	cout <<"\t"<< node->val;
	traversal(node->left);
	traversal(node->right);
}
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
		cout <<"Usage: ./createTreev 30 50 50 2 3 3 2"<<endl;
		exit(1);
	}

	int len = argc -1 ;
	cout << len <<endl;

	int *data = (int *)malloc(sizeof(int) * len);
	memset(data, 0, sizeof(char)*len);
	for(int i=1; i<argc; i++)
	{
		if(*argv[i] != '#')
			data[i-1] = atoi(argv[i]) ;
		else
			data[i-1] = '#';
	}
	for(int i=0; i < len ; i++)
		cout <<"\t"<< data[i] ;
	cout << endl;
	cout << endl;

	TreeNode *tree = NULL;
	tree = constructTree(data, len);

	traversal(tree);
	cout << endl;

	Solution s;
	cout << s.isSymmetric(tree) <<endl;
}