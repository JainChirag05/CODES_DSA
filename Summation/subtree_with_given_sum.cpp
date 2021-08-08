#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newnode(int val)
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

bool check(Node *root , int *curr , int sum)
{
	if(root == NULL)
	{
		*curr = 0;
		return false;
	}

	int lsum = 0;
	int rsum = 0;

	bool left = check(root->left , &lsum , sum);
	bool right = check(root->right , &rsum , sum);

	*curr = lsum + rsum + root->data;

	return (left || right || *curr == sum);
}

bool final(Node *root , int sum)
{
	int curr = 0;

	return check(root , &curr , sum);
}

int main()
{
    struct Node *root = newnode(8);
    root->left    = newnode(5);
    root->right   = newnode(4);
    root->left->left = newnode(9);
    root->left->right = newnode(7);
    root->left->right->left = newnode(1);
    root->left->right->right = newnode(12);
    root->left->right->right->right = newnode(2);
    root->right->right = newnode(11);
    root->right->right->left = newnode(3);
    int sum = 22;
 
    if (final(root, sum))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}