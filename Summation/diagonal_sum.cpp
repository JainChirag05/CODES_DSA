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

void solve(Node *root)
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

		int sum = 0;

		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			while(temp)
			{
				sum += temp->data;

				if(temp->left)
				{
					q.push(temp->left);
				}

				temp = temp->right;
			}

		}

		cout << sum << endl;
	}
}
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);
 
    solve(root);

    //cout << sum << endl;
 
    return 0;
}