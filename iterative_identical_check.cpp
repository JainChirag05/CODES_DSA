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

bool check(Node *root1 , Node *root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}

	if(root1 == NULL || root2 == NULL)
	{
		return false;
	}

	queue <Node*> q1;
	queue <Node*> q2;

	q1.push(root1);
	q2.push(root2);

	while(!q1.empty() && !q2.empty())
	{
		Node *t1 = q1.front();
		Node *t2 = q2.front();

		if(t1->data != t2->data)
		{
			return false;
		}

		q1.pop();
		q2.pop();

		if(t1->left && t2->left)
		{
			q1.push(t1->left);
			q2.push(t2->left);
		}

		else if(t1->left || t2->left)
		{
			return false;
		}

		if(t1->right && t2->right)
		{
			q1.push(t1->right);
			q2.push(t2->right);
		}

		else if(t1->right || t2->right)
		{
			return false;
		}
	}

	return true;
}

int main()
{
    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
  
    Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
  
    check(root1, root2)? cout << "Yes"
                              : cout << "No";
    return 0;
}