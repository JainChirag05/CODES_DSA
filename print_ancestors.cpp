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

bool solve(Node *root , int n)
{
	if(root == NULL)
	{
		return false;
	}

	if(root->data == n)
	{
		//cout << "No ancestor" << " ";
		return true;
	}

	if(solve(root->left , n) || solve(root->right , n))
	{
		cout << root->data << " ";
		return true;
	}

	return false;
}

int main()
{
  
  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(7);
  
  solve(root, 7);
  
  //getchar();
  return 0;
}