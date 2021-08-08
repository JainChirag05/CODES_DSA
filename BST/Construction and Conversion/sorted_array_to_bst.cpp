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

void preOrder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

Node *search(Node *root , int val)
{
	if(root->data == val)
	{
		return root;
	}

	if(root->data < val)
	{
		return search(root->right , val);
	}

	else
	{
		return search(root->left , val);
	}
}

Node *convert(int arr[] , int st , int end)
{
	if(st > end)
	{
		return NULL;
	}

	int mid = (st+end)/2;

	Node *root = newNode(arr[mid]);

	root->left = convert(arr , st , mid-1);
	root->right = convert(arr , mid+1 , end);

	return root;
}

Node *final(int arr[] , int n)
{
	return convert(arr , 0 , n-1);
}

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    /* Convert List to BST */
    Node *root = final(arr, n); 
    cout << "PreOrder Traversal of constructed BST \n"; 
    preOrder(root); 
  
    return 0; 
} 