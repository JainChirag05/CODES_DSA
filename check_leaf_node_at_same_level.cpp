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

bool solve(Node *root , int lev , int &val)
{
	if(root == NULL)
	{
		return true;
	}

	if(root->left == NULL && root->right == NULL)
	{
		if(val == -1)
		{
			val = lev;
		}

		return (lev == val);
	}

	return solve(root->left , lev+1 , val) && solve(root->right , lev+1 , val);
}

bool final(Node *root)
{
	int val = -1;

	return solve(root , 0 , val);
}

int main()
{
    // Let us create tree shown in third example
    Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (final(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
   // getchar();
    return 0;
}