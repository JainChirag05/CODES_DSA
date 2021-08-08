#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// TC of O(n) and SC of O(n)

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

void spiral(Node *root)
{
	stack <Node*> s1; // right to left
	stack <Node*> s2; //left to right

	s1.push(root);

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			Node *temp = s1.top();
			s1.pop();

			cout << temp->data << " ";

			if(temp->right != NULL)
			{
				s2.push(temp->right);
			}

			if(temp->left != NULL)
			{
				s2.push(temp->left);
			}
		}

		while(!s2.empty())
		{
			Node *temp2 = s2.top();
			s2.pop();

			cout << temp2->data << " ";

			if(temp2->left != NULL)
			{
				s1.push(temp2->left);
			}

			if(temp2->right != NULL)
			{
				s1.push(temp2->right);
			}
		}
	}
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    spiral(root);
  
    return 0;
}