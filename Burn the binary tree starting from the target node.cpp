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

void burning_tree_node(Node* root, Node* block, int time, vector<vector<int>> & ans)
{
	if (root == NULL or root == block)
	{
		return;
	}

	if (time == ans.size())
	{
		ans.push_back({});
	}
	ans[time].push_back(root->val);


	burning_tree_node(root->left, block, time + 1, ans);
	burning_tree_node(root->right, block, time + 1, ans);
}

int help(Node* root, int target, vector<vector<int>>& ans)
{
	if (root == NULL)
	{
		return -1;
	}

	if (root->val == target)
	{
		//ans.push_back(root->val);
		burning_tree_node(root, NULL, 0, ans);
		return 1;
	}

	int ld = help(root->left, target, ans);
	if (ld > 0)
	{
		burning_tree_node( root, root->left, ld, ans );
		return ld + 1;
	}

	int rd = help(root->right, target, ans);
	if (rd > 0)
	{
		burning_tree_node( root , root->right , rd , ans );
		return rd + 1;
	}

	return -1;


}

void burnTree(Node* root, int data) {
	vector<vector<int>> ans ;
	help(root, data, ans);

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
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif

	//solve();

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

	// Function call
	burnTree(root, targetNode);

	return 0;




}
