class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root)
	{
		std::vector<vector<int> > result;
		if(root==nullptr) return result;
		std::vector<int> level;
		queue<TreeNode *> current,next;
		current.push(root);
		while(!current.empty())
		{
			while(!current.empty())
			{
				TreeNode *node=current.front();
				current.pop();
				level.push_back(node->val);
				if(node->left!=nullptr) next.push(node->left);
				if(node->right!=nullptr) next.push(node->right);
			
			}

			result.push_back(level);
			level.clear();
			swap(current,next);

		}
		return result;
	}

};