bool isSymmetric(TreeNode *root)
{
	if ((root==NULL) || (root->left==NULL && root->right==NULL))
		return true;
	return dfs(root->left,root->right)

}

bool dfs(TreeNode *left,TreeNode *right)
{
	if (left==NULL && right==NULL)
		return true;
	if ((left==NULL) || (right==NULL) || (left->val != right->val))
		return false;
	return dfs(left->left,right->right) && dfs(left->right,right->left);

}