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

//max height is at most twice the minimum height

bool height(Node *root , int &maxi , int &mini)
{
	if(root == NULL)
	{
		maxi = 0;
		mini = 0;
		return true;
	}

	int lmax , lmin;
	int rmax , rmin;
	if(height(root->left , lmax , lmin) == false)
	{
		return false;
	}

	if(height(root->right , rmax , rmin) == false)
	{
		return false;
	}

	maxi = max(lmax , rmax) + 1;
	mini = min(lmin , rmin) + 1;

	if(maxi <= 2 * mini)
	{
		return true;
	}

	return false;
}

int main()
{
    Node * root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(100);
    root->right->left = newNode(50);
    root->right->right = newNode(150);
    root->right->left->left = newNode(40);
    int maxi;
    int mini;
    height(root, maxi , mini)? cout << "Balanced" : cout << "Not Balanced";
 
    return 0;
}