#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int val)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;

	temp->data = val;	

	return temp;
}

void inorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int solve(Node *root)
{
	//exp complexity

	if(root == NULL)
	{
		return 0;
	}

	int ex = solve(root->left) + solve(root->right);

	int in = 1;

	if(root->left)
	{
		in += solve(root->left->left) + solve(root->left->right);
	} 

	if(root->right)
	{
		in += solve(root->right->left) + solve(root->right->right);
	}

	return max(ex , in);
}

unordered_map <Node* , int> dp;

int solve_dp(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	if(dp[root])
	{
		return dp[root];
	}

	if(root->left == NULL && root->right == NULL)
	{
		return dp[root] = 1;
	}

	int ex = solve_dp(root->left) + solve_dp(root->right);

	int in = 1;

	if(root->left)
	{
		in += solve_dp(root->left->left) + solve_dp(root->left->right);
	} 

	if(root->right)
	{
		in += solve_dp(root->right->left) + solve_dp(root->right->right);
	}

	dp[root] =  max(ex , in);

	return dp[root];
}

int main() 
{ 
    // Let us construct the tree 
    // given in the above diagram 
    Node *root     = newNode(20); 
    root->left         = newNode(8); 
    root->left->left     = newNode(4); 
    root->left->right     = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right         = newNode(22); 
    root->right->right     = newNode(25); 

    cout << "Size of the Largest Independent Set is " << solve(root) <<endl;
    cout << "Size of the Largest Independent Set is " << dp(root) <<endl; 

    return 0; 
}