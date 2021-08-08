#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *createNode(int val)
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

int sum = 0;
int max_level = INT_MIN;

void solve(Node *root , int level)
{
	if(root == NULL)
	{
		return;
	}

	if(level > max_level)
	{
		sum = root->data;
		max_level = level;
	}

	else if(level == max_level)
	{
		sum += root->data;
	}

	solve(root->left , level + 1);
	solve(root->right , level + 1);
}

int final(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	solve(root , 0);

	return sum;	
}

int iter(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();

		sum = 0;
		
		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			sum += temp->data;

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

	return sum;
}

int main()
{
    Node *root;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    cout << final(root) <<endl;
    cout << iter(root) << endl;
    //cout << sum;
    return 0;
}