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

bool check(Node *n1, Node *n2)
{
	if(n1 == NULL && n2 == NULL)
	{
		return true;
	}

	else
	{
		return ((n1->data == n2->data) || check(n1->left , n2->right) || check(n1->right , n2->left));
	}
}

int main() 
{ 
    Node *root1 = newNode(1); 
    Node *root2 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
  
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5); 
  
    if(check(root1, root2)) 
        cout << "Both tree are identical."; 
    else
        cout << "Trees are not identical."; 
  
return 0; 
}