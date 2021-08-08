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

Node *recur(Node *n1 , Node *n2)
{
	if(n1 == NULL)
	{
		return n2;
	}

	if(n2 == NULL)
	{
		return n1;
	}

	n1->data += n2->data;

	n1->left = recur(n1->left , n2->left);
	n1->right = recur(n1->right , n2->right);

	return n1;
}

int main()
{
    /* Let us construct the first Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
    Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->right = newNode(6);
 
    /* Let us construct the second Binary Tree
           4
         /   \
        1     7
       /     /  \
      3     2    6   */
    Node *root2 = newNode(4);
    root2->left = newNode(1);
    root2->right = newNode(7);
    root2->left->left = newNode(3);
    root2->right->left = newNode(2);
    root2->right->right = newNode(6);
 
    Node *root3 = recur(root1, root2);
    printf("The Merged Binary Tree is:\n");
    inorder(root3);
    return 0;
}