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

int solve(int l)
{
	int leaves = pow(2 , l-1);

	int leaves_sum = leaves*(leaves+1)/2;

	return leaves_sum*l;
}

int main()
{
    int l = 3;
    cout << solve(l);
    return 0;
}