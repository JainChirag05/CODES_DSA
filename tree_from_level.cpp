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
	temp->data = val;
	temp->left = temp->right = NULL;

	return temp;
}

Node* build(int arr[] , int i , Node *root , int n)
{
	Node *temp;

	if(i < n)
	{
		temp = newNode(arr[i]);

		temp->left = build(arr , 2*i+1,root->left , n);
		temp->right = build(arr , 2*i+2,root->right , n);
	}

	return temp;
}

void inorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	inorder(root -> left);
	cout << root->data << " ";
	inorder(root->right);
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = build(arr, 0, root, n);
    inorder(root);
}