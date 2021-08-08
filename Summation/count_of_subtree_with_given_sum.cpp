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

int check(Node *root , int &count , int sum)
{
	if(root == NULL)
	{
		return 0;
	}

	int l = check(root->left , count , sum);
	int r = check(root->right , count , sum);

	int x = l + r + root->data;

	if(x == sum)
	{
		count++;
	}

	return x;
}

int solve(Node *root , int sum)
{
	int count = 0;

	if(root == NULL)
	{
		return 0;
	}

	int l = check(root->left , count , sum);
	int r = check(root->right , count,  sum);

	if(r + l + root->data == sum)
	{
		count++;
	}

	return count;
}

int main()
{
    /* binary tree creation   
                5
              /   \ 
           -10     3
           /  \   /  \
          9    8 -4   7
    */
    Node* root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);
 
    int x = 7;
 
    cout << "Count = "
         << solve(root, x);
 
    return 0;
}