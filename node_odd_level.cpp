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

void solverecur(Node *root , bool check = true)
{
	if(root == NULL)
	{
		return;
	}

	if(check)
	{
		cout << root->data << " ";
	}

	solverecur(root->left , !check);
	solverecur(root->right , !check);

}

void solveiter(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	queue <Node*> q;
	q.push(root);

	bool check = true;

	while(!q.empty())
	{
		int n = q.size();

		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			if(check)
			{
				cout << temp->data << " ";
			}

			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}

			n--;
		}

		check = !check ; 
	}
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    solverecur(root);
    solveiter(root);
 
    return 0;
}