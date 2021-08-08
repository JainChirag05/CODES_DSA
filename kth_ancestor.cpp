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

Node *solve(Node *root , int n , int &k)
{
	if(root == NULL)
	{
		return NULL;
	}

	Node *temp = NULL;

	if(root->data == n || (temp = solve(root->left , n , k)) || (temp = solve(root->right , n , k)))
	{
		if(k > 0)
		{
			k--;
		}

		else if(k == 0)
		{
			cout << root->data;

			return NULL;
		}

		return root;
	}

	return NULL;
}

int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
  
    int k = 2;
    int node = 5;
  
    // print kth ancestor of given node
    Node* parent = solve(root,node,k);
      
    // check if parent is NULL, it means
    // there is no Kth ancestor of the node
    if (parent != NULL)
        cout << "-1";
      
    return 0;
}