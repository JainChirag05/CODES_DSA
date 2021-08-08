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

//M1 -- sort level order to get inorder and then construct. This is O(nlogn)

Node *create(Node *root , int val)
{
	if(root == NULL)
	{
		root = newNode(val);
		return root;
	}

	if(val <= root->data)
	{
		root->left = create(root->left , val);
	}

	else
	{
		root->right = create(root->right , val);
	}

	return root;
}

Node *final(int level[] , int n)
{
	Node *root = NULL;
	
	if(n == 0)
	{
		root = NULL;
	}

	for(int i = 0;i<n;i++)
	{
		root = create(root , level[i]);
	}

	return root;
}

int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
      
    Node *root = final(arr, n);
      
    cout << "Inorder Traversal: ";
    inorder(root);
    return 0;    
} 

