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

int height (Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	else
	{
		int lefth = height(root->left);
		int righth = height(root->right);
		
		if(lefth > righth)
		{
			return (lefth + 1);
		}
		
		else
		{
			return (righth + 1);
		}
	}
}

void printcurr(Node *root , int level)
{
	if(root == NULL)
	{
		return;
	}
	
	if(level == 1)
	{
		cout << root->data <<" ";
	}
	
	else if (level > 1)
	{
		printcurr(root->left , level-1);
		printcurr(root->right , level-1);
	}
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
		printcurr(root, i);
	}
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}
