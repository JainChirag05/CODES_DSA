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

Node *lca(Node *root , int n1 , int n2)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(root->data == n1 || root->data == n2)
	{
		return root;
	}

	Node *l = lca(root->left , n1 , n2);
	Node *r = lca(root->right , n1 , n2);

	if(r != NULL && l!= NULL)
	{
		return root;
	}

	if(l == NULL && r == NULL)
	{
		return NULL;
	}

	else
	{
		if(r != NULL && l == NULL)
		{
			return r;
		}

		else
		{
			return l;
		}
	}
}

int dist(Node *root , int n , int st)
{
	if(root == NULL)
	{
		return -1;
	}

	if(root->data == n)
	{
		return st;
	}

	int l = dist(root->left , n ,st+1);

	if(l != -1)
	{
		return l;
	}

	return dist(root->right , n ,st+1);
}

int distance(Node *root , int n1 , int n2)
{
	Node *temp = lca(root , n1 , n2);

	int d1 = dist(temp , n1 , 0);
	int d2 = dist(temp , n2 , 0);

	return d1 + d2;
}

int main()
{
    // Let us create binary tree given in the
    // above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << distance(root, 4, 5);
    cout << "\nDist(4, 6) = " << distance(root, 4, 6);
    cout << "\nDist(3, 4) = " << distance(root, 3, 4);
    cout << "\nDist(2, 4) = " << distance(root, 2, 4);
    cout << "\nDist(8, 5) = " << distance(root, 8, 5);
    return 0;
}