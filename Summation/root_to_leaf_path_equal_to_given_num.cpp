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

bool solve(Node *root , int k)
{
	bool ans = 0;

	if(root == NULL)
	{
		return (k == 0);
	}

	else
	{
		int diff = k - root->data;

		if(diff == 0 && root->left == NULL && root->right == NULL)
		{
			return 1;
		}

		if(root->left)
		{
			ans = ans || solve(root->left , diff);
		}

		if(root->right)
		{
			ans = ans || solve(root->right , diff);
		}
	}

	return ans;
}

int main()
{
 
    int sum = 22;
    
    /* Constructed binary tree is
                10
            / \
            8 2
        / \ /
        3 5 2
    */
    Node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
     
    if(solve(root, sum))
        cout << "There is a root-to-leaf path with sum " << sum;
    else
        cout << "There is no root-to-leaf path with sum " << sum;
     
    return 0;
}