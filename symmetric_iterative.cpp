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

bool check(Node *root)
{
	if(root == NULL)
	{
		return true;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return true;
	}

	queue <Node*> q1;
	queue <Node*> q2;

	q1.push(root);
	q2.push(root);

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

		if(t1->left && t2->right)
		{
			q1.push(t1->left);
			q2.push(t2->right);
		}

		else if(t1->left || t2->right)
		{
			return false;
		}

		if(t1->right && t2->left)
		{
			q1.push(t1->right);
			q2.push(t2->left);
		}

		else if(t1->right || t2->left)
		{
			return false;
		}
	}

	return true;
}

int main()
{
    // Let us construct the Tree shown in
    // the above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
 
    if(check(root))
        cout << "The given tree is Symmetric";
    else
        cout << "The given tree is not Symmetric";
    return 0;
}