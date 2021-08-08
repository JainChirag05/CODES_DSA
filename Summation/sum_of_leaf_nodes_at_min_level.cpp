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

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return root->data;
	}

	queue <Node*> q;
	q.push(root);

	int sum = 0;
	bool f = 0;

	while(f == 0)
	{
		int n = q.size();

		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			if(temp->left == NULL && temp->right == NULL)
			{
				sum += temp->data;

				f = 1;
			}

			else
			{
				if(temp->left)
				{
					q.push(temp->left);
				}

				if(temp->right)
				{
					q.push(temp->right);
				}
			}
		}
	}

	return sum;
}

int main()
{
    // binary tree creation
    Node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->right->left = getNode(8);
    root->right->left->right = getNode(9);
  
    cout << "Sum = "
         << solve(root);
  
    return 0;
}