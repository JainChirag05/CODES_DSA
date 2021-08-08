#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Also called as width of the tree and the number of nodes in the longest path between two leaf nodes

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


   
int height(Node *root)
{
    int lefth;
    int righth;
    
    if(root == NULL)
    {
        return 0;
    }
    
    else
    {
        lefth = height(root->left);
        righth = height(root->right);
    }
        
    return max(lefth + 1 , righth + 1);
}
    
int diameter(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
       
    int lefth = height(root->left);
    int righth = height(root->right);
       
    int dial = diameter(root->left);
    int diar = diameter(root->right);
       
       
    return max((lefth + righth), max(diar,dial));
}

int main()
{
 
    /* Constructed binary tree is
         1
        / \
       2   3
       / \
      4   5
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->left->left->right = newNode(8);
    root->left->left->right->left = newNode(9);
 
    // Function Call
    cout << "Diameter of the given binary tree is " <<
        diameter(root);
 
    return 0;
}