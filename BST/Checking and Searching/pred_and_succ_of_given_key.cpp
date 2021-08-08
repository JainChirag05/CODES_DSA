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

Node *search(Node *root , int val)
{
	if(root->data == val)
	{
		return root;
	}

	if(root->data < val)
	{
		return search(root->right , val);
	}

	else
	{
		return search(root->left , val);
	}
}

Node* insert(Node* node, int val)
{
  if (node == NULL)
  {
  	return newNode(val);
  }    
 
  if (val < node->data)
  {
		node->left = insert(node->left, val);
  }
  
  else if (val > node->data)
  {
   	node->right = insert(node->right, val);
  }    
 
  return node;
}

void solve(Node *root , Node *&pre , Node *&suc , int key)
{
	if(root == NULL)
	{
		return;
	}

	if(root->data == key)
	{
		if(root->left) //rightmost root in left subtree is pred
		{
			Node *temp = root->left;

			while(temp->right)
			{
				temp = temp->right;
			}

			pre = temp;
		}

		if(root->right) //leftmost root in right subtree is suc
		{
			Node *temp2 = root->right;

			while(temp2->left)
			{
				temp2 = temp2->left;
			}

			suc = temp2;
		}

		return;
	}

	if(root->data > key)
	{
		suc = root;
		solve(root->left , pre , suc , key);
	}

	else
	{
		pre = root;
		solve(root->right , pre , suc , key);
	}
}

int main()
{
    int key = 65;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    Node* pre = NULL, *suc = NULL;
 
    solve(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
    return 0;
}