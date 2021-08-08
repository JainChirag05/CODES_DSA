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

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int odd = 0;
	int even = 0;

	queue <Node*> q;
	q.push(root);

	bool itr = true;

	while(!q.empty())
	{
		int n = q.size();

		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			if(itr)
			{
				odd += temp->data;
			}

			else
			{
				even += temp->data;
			}

			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}

		itr =! itr;
	}

	return (odd - even);
}

int main()
{
    Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
    cout<<solve(root)<<" is the required difference\n";
    return 0;
}