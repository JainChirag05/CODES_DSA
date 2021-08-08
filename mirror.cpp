
#include <bits/stdc++.h>
#define ll long long int
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
	
	return temp;
}

void mirrori(Node* root)
{
    if(root == NULL)
    {
        return;
    }
        
    mirrori(root->left);
    mirrori(root->right);
        
    swap(root->left , root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
 
    Node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
 
    // Print inorder traversal of the input tree
    cout << "Inorder of original tree: ";
    inorder(tree);
    //Node* mirror = NULL;

    mirrori(tree);
 
    // Print inorder traversal of the mirror tree
    cout << "\nInorder of mirror tree: ";
    inorder(tree);
 
    return 0;
}