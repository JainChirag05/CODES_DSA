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

bool leaf(Node *root)
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

bool check(Node *n1 , Node *n2)
{
	stack <Node*> st1;
	stack <Node*> st2;

	st1.push(n1);
	st2.push(n2);

	while(!st1.empty() || !st2.empty())
	{
		if(st1.empty() || st2.empty())
		{
			return false;
		}

		Node *temp1 = st1.top();
		st1.pop();

		while(temp1 != NULL && !leaf(temp1))
		{
			if(temp1->right)
			{
				st1.push(temp1->right);
			}

			if(temp1->left)
			{
				st1.push(temp1->left);
			}

			temp1 = st1.top();
			st1.pop();
		}

		Node *temp2 = st2.top();
		st2.pop();

		while(temp2 != NULL && !leaf(temp2))
		{
			if(temp2->right)
			{
				st2.push(temp2->right);
			}

			if(temp2->left)
			{
				st2.push(temp2->left);
			}

			temp2 = st2.top();
			st2.pop();
		}

		if(!temp1 && temp2)
		{
			return false;
		}

		if(temp1 && !temp2)
		{
			return false;
		}

		if(temp1 && temp2)
		{
			if(temp1->data != temp2->data)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
    Node* root1 = newNode(0);
    root1->left = newNode(1);
    root1->right = newNode(2);
    root1->left->left = newNode(8);
    root1->left->right = newNode(9);
    //root1->right->right = newNode(7);
  
    Node* root2 = newNode(1);
    root2->left = newNode(4);
    root2->right = newNode(3);
    root2->left->right = newNode(8);
    root2->right->left = newNode(2);
    root2->right->right = newNode(9);	
  
    if (check(root1, root2))
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}