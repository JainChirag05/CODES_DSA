#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *getNode(int val)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;

	temp->data = val;

	return temp;
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


void store_inorder(Node *root , vector<int> &arr)
{
	if(root == NULL)
	{
		return;
	}

	store_inorder(root->left , arr);
	arr.push_back(root->data);
	store_inorder(root->right , arr);
}

void build(Node *root , vector <int> &arr , int *i)
{
	if(root == NULL)
	{
		return;
	}

	root->data = arr[++*i];

	build(root->left , arr , i);
	build(root->right , arr , i);
}

void final(Node *root)
{
	vector <int> arr;

	store_inorder(root , arr);

	int i = -1;

	build(root , arr , &i);
}

void preoder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preoder(root->left);
	preoder(root->right);
}

int main()
{
    // BST formation
    Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    final(root);
    cout << "Preorder Traversal:" << endl;
    preoder(root);
 
    return 0;
}




