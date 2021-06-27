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
    
void print_kdown(TreeNode* root,TreeNode* block,vector<int>& ans,int k)
{
	if(root==NULL or k<0 or root==block )
	{
		return;
	}

	if(k==0)
	{
		ans.push_back(root->val);
		return;
	}

	print_kdown(root->left,block,ans,k-1);
	print_kdown(root->right,block,ans,k-1);


}
    
    
    
bool help(TreeNode* root, int data, vector<TreeNode* > & ans)
{


	if (root == NULL )
	{
		return false;
	}
	if (root->val == data)
	{
		ans.push_back(root);
		return true;
	}



	bool lft = help(root->left, data, ans);
	bool rgt = help(root->right, data, ans);

	if (lft)
	{
		ans.push_back(root);
		return true;
	}

	if (rgt)
	{
		ans.push_back(root);
		return true;
	}

	return false;
}

vector<TreeNode*> nodeToRootPath(TreeNode* root, int data)
{
	vector<TreeNode* > ans;
	help(root, data, ans);


	return ans;
}
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    vector<TreeNode* > path=nodeToRootPath(root,target->val);

	TreeNode* block=NULL;
	vector<int> vect;

	for(int i=0;i<path.size();i++)
	{
		print_kdown(path[i],block,vect,k-i);
		block=path[i];
	}

	return vect;
        
    }
};
