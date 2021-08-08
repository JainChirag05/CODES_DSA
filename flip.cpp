#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->left = temp->right = NULL;

	return temp;
}

Node *flip(Node *root)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return root;
	}

	Node *temp = flip(root->left);

	root->left->left = root->right;
	root->left->right = root;
	root->left = root->right = NULL;

	return temp;
}

void level(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();
		
		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			cout << temp->data << " ";

			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}

		cout << endl;
	}
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
 
    cout << "Level order traversal of given tree\n";
    level(root);
 
    root = flip(root);
 
    cout << "\nLevel order traversal of the flipped"
            " tree\n";
    level(root);

    return 0;
}