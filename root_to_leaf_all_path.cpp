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

void solve (Node *root , vector <int> &path)
{
	if(root == NULL)
	{
		return;
	}	

	path.push_back(root->data);

	if(root->left == NULL && root->right == NULL)
	{
		for(int i = 0;i<path.size();i++)
		{
			cout << path[i] << " ";
		}

		cout << endl;
	}

	solve(root->left , path);
	solve(root->right , path);

	path.pop_back(); //impt
}

int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
               /     \
              8       9
    */
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->left = newNode(8);
    root->right->right->right = newNode(9);
 
  	vector <int> path;
    solve(root , path);
  
    return 0;
}