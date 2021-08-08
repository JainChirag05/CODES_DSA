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

int calc(Node *root , int &size)
{
	if(root == NULL)
	{
		return 0;
	}
	
	else
	{
		int l = calc(root->left , size);
		int r = calc(root->right , size);
		
		size++;
	
		if(r > l)
		{
			return r+1;
		}
	
		else
		{
			return l+1;
		}
	}
}

float density(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int size = 0;
	
	int height = calc(root , size);
	
	return (float)size/height;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
  
    printf("Density of given binary tree is %f",density(root));
  
    return 0;
}
		
