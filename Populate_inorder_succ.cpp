#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *next;
};

Node *createnode(int num)
{
	Node *temp = new Node();
	
	temp->data = num;
	temp->left = temp->right = temp->next = NULL;
	
	return temp;
}

void next(Node *curr , Node *&prev)
{
	if(curr == NULL)
	{
		return;
	}
	
	next(curr->left , prev);
	
	if(prev != NULL)
	{
		prev->next = curr;
	}
	
	prev = curr;
	
	next(curr->right , prev);
}

void inorder(Node *curr)
{
	Node* prev = NULL;
 

    next(curr, prev);
 
    curr = curr->left->left; //impt
 
    while (curr->next)
    {
        cout << "The inorder successor of " << curr->data << " is "
             << curr->next->data << endl;
        curr = curr->next;
    }
}

int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         /      /  \
        /      /    \
       4      5      6
             / \
            /   \
           7     8
    */
 
    Node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->right->left = createnode(5);
    root->right->right = createnode(6);
    root->right->left->left = createnode(7);
    root->right->left->right = createnode(8);
 
    inorder(root);
 
    return 0;
}


