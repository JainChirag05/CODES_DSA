#include <bits/stdc++.h>

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

void solve(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node *temp = q.front();
		
		cout << temp->data << " ";
		q.pop();
		
		if(temp->left != NULL)
		{
			q.push(temp->left);
		}
		
		if(temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}

int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
 
    cout << "Level Order traversal of binary tree is \n";
    solve(root);
    return 0;
}
	
	
