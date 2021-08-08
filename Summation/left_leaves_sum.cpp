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

bool isleaf(Node *root)
{
	if(root == NULL)
	{
		return false;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return true;
	}

	return false;
}

int final_recur(Node *root)
{
	int sum = 0;

	if(root == NULL)
	{
		return 0;
	}

	else
	{
		if(isleaf(root->left))
		{
			sum += root->left->data;
		}

		else
		{
			sum += final_recur(root->left);
		}

		sum += final_recur(root->right);
	}

	return sum;
}

int final_iter(Node *root)
{
	int sum = 0;
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if(temp->left)
		{
			if(isleaf(temp->left))
			{
				sum += temp->left->data;
			}

			q.push(temp->left);
		}

		if(temp->right)
		{
			q.push(temp->right);
		}
	}

	return sum;
}


int main()
{
    // Let us a construct the Binary Tree
    Node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(2);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);
    cout << "Sum of left leaves is "
         << final_recur(root) <<endl;

    cout << "Sum of left leaves is "
         << final_iter(root) <<endl;
    return 0;
}