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

Node* insert(Node* node, int val , Node*& succ)
{
	if(node == NULL)
	{
		return node = newNode(val);
	}

	if(val < node->data)
	{
		succ = node;
		node->left = insert(node->left , val , succ);
	}

	else if(val > node->data)
	{
		node->right = insert(node->right , val , succ);
	}

	return node;    
}

void solve(int arr[] , int n)
{
	Node *root = NULL;

	for(int i = n-1;i>=0;i--)
	{
		Node *succ = NULL;

		root = insert(root , arr[i] , succ);

		if(succ)
		{
			arr[i] = succ->data;
		}

		else
		{
			arr[i] = -1;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	solve(arr , n);

	for(int i = 0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}



