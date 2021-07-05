# pep_trees
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
    
    TreeNode* lca = NULL;

bool LCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL)
	{
		return false;
	}

	bool self = (root == p or root == q);

	bool lft = LCA(root->left, p, q);
	bool rgt = LCA(root->right, p, q);

	if ((lft and rgt) or (self and rgt) or (self and lft))
	{
		lca = root;
	}

	return (lft or rgt or self);



}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root, p, q);
	return lca;
        
    }
};
