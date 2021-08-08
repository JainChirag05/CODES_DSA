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

void right(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();

		for(int i = 0;i<n;i++)
		{
			Node *temp = q.front();
			q.pop();

			if(i == n-1)
			{
				cout << temp->data << " ";
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
	}
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
  
    right(root);
  
    return 0;
}