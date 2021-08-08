#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *createNode(int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->left = temp->right = NULL;
}

bool fold(Node *n1 , Node *n2)
{
	if(n1 == NULL && n2 == NULL)
	{
		return true;
	}
	
	if(n1 == NULL || n2 == NULL)
	{
		return false;
	}
	
	return (fold(n1->left , n2->right) && fold(n1->right , n2->left));
}

bool check(Node *root)
{
	if(root == NULL)
	{
		return true;
	}
	
	return fold(root->left , root->right);
}

int main()
{
    /* The constructed binary tree is
         1
        / \
        2 3
        \ /
        4 5
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(5);
 
    if (check(root) == true) 
    {
        cout << "Tree is foldable";
    }
    else 
    {
        cout << "Tree is not foldable";
    }
 
    return 0;
}
