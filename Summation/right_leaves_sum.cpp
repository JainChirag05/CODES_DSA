#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *addNode(int val)
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

int final(Node *root)
{
	int sum = 0;

	if(root == NULL)
	{
		return 0;
	}

	else
	{
		if(isleaf(root->right))
		{
			sum += root->right->data;
		}

		else
		{
			sum += final(root->right);
		}

		sum += final(root->left);
	}

	return sum;
}

int iter(Node *root)
{
	int sum = 0;
	
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if(temp->left)
		{
			q.push(temp->left);
		}

		if(temp->right)
		{
			if(isleaf(temp->right))
			{
				sum += temp->right->data;
			}

			q.push(temp->right);
		}
	}

	return sum;
}

int main()
{
     
        //construct binary tree
    Node *root = addNode(1);
    root->left = addNode(2);
    root->left->left = addNode(4);
    root->left->right = addNode(5);
    root->left->left->right = addNode(2);
    root->right = addNode(3);
    root->right->right = addNode(8);
    root->right->right->left = addNode(6);
    root->right->right->right = addNode(7);
 
    // variable to store sum of right
       // leaves
  	cout << final(root) << endl;
  	cout << iter(root);
   return 0;
}