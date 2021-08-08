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

int sum = 0;

int solve(Node *root , int &sum)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->left == NULL && root->right == NULL)
	{
		sum += root->data;
	}

	solve(root->left , sum);
	solve(root->right , sum);

	return sum;
}

int main(){
      
    //construct binary tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->right = newNode(7);
    root->right->left = newNode(6);
    root->right->left->right = newNode(8);
      
    // variable to store sum of leaf nodes
    cout << solve(root , sum) << endl;
    return 0;
}