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

void solve(Node *root , vector <int> &path , int k)
{
	if(root == NULL)
	{
		return;
	}

	path.push_back(root->data);

	solve(root->left , path , k);
	solve(root->right , path , k);

	int sum = 0;

	for(int i = path.size()-1 ; i>=0;i--)
	{
		sum += path[i];

		if(sum == k)
		{
			for(int j = i;j <= path.size()-1;j++)
			{
				cout << path[j] << " ";
			}

			cout << endl;
		}
	}

	path.pop_back();
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);
  
    int k = 5;
    vector <int> path;
    solve(root, path ,k);
  
    return 0;
}