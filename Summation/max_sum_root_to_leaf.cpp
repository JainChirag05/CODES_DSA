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

int maxsum(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int l = maxsum(root->left);
	int r = maxsum(root->right);

	int res = max(l,r);

	return res + root->data;
}

bool printpath(Node *root , int sum)
{
	if(sum == 0)
	{
		return true;
	}

	if(root == NULL)
	{
		return false;
	}

	bool l = printpath(root->left , sum-root->data);
	bool r = printpath(root->right , sum-root->data);

	if(l || r)
	{
		cout << root->data << " ";
	}

	return r||l;
}

void final(Node *root)
{
	int sum = maxsum(root);
   cout << "The Maximum sum is " << sum << endl;
   cout << "The Maximum sum path is ";
 
   printpath(root, sum);
}

int main()
{
	/* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        8   4   5   6
           /   / \   \
         10   7   9   5
    */
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->left->right->left = newNode(10);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(9);
    root->right->right->right = newNode(5);
 	
 	final(root);

    return 0;
}