#include<bits/stdc++.h>
using namespace std;


struct Node {
	int val;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->val = val;
	temp->left = temp->right = NULL;
	return (temp);
}

void burning_treenode_withwater(Node* root, Node* block, int time, vector<vector<int>> & ans, unordered_set<int>& waterset)
{
	if (root == NULL or root == block or waterset.find(root->val) != waterset.end())
	{
		return;
	}

	if (time == ans.size())
	{
		ans.push_back({});
	}

	ans[time].push_back(root->val);

	burning_treenode_withwater(root->left, block, time + 1, ans, waterset);
	burning_treenode_withwater(root->right, block, time + 1, ans, waterset);
}

int help(Node* root, int firenode, vector<vector<int>> & ans, unordered_set<int>& waterset)
{
	if (root == NULL )
	{
		return -1;
	}
	if (root->val == firenode)
	{
		if (waterset.find(firenode) == waterset.end())
		{
			burning_treenode_withwater(root, NULL, 0, ans, waterset);
			return 1;
		}
		return -2;
	}

	int ld = help(root->left, firenode, ans, waterset);
	if (ld > 0)
	{
		if (waterset.find(root->val) == waterset.end())
		{
			burning_treenode_withwater(root, root->left, ld, ans, waterset);
			return ld + 1;
		}
		return -2;
	}
	if (ld == -2)
	{
		return -2;
	}


	int rd = help(root->right, firenode, ans, waterset);

	if (rd > 0)
	{
		if (waterset.find(root->val) == waterset.end())
		{
			burning_treenode_withwater(root, root->right, rd, ans, waterset);
			return rd + 1;
		}
		return -2;
	}
	if (rd == -2)
	{
		return -2;
	}

	return -1;
}


void burnTree(Node* root, int data) {
	vector<vector<int>> ans ;
	unordered_set<int> waterset;
	waterset.insert(15);
	waterset.insert(10);

	help(root, data, ans, waterset);

	for (auto z : ans)
	{
		for (auto x : z)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}


int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*      10
	       /  \
	      12  13
	          / \
	         14 15
	        / \ / \
	      21 22 23 24

	    Let us create Binary Tree as shown
	    above */

	Node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(13);

	root->right->left = newNode(14);
	root->right->right = newNode(15);

	root->right->left->left = newNode(21);
	root->right->left->right = newNode(22);
	root->right->right->left = newNode(23);
	root->right->right->right = newNode(24);
	int targetNode = 14;

	burnTree(root, targetNode);
}
