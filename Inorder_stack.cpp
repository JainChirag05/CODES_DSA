#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	
	Node (int num)
	{
		this->data = num;
		left=right = NULL;
	}
};

void inorder(Node *root)
{
	stack <Node*> s;
	Node *curr = root;
	
	while(curr != NULL || !s.empty())
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		
		curr = s.top();
		s.pop();
		
		cout << curr->data << " ";	
			
		curr = curr->right;
	}
}

int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    Node *root 		  =	new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    inorder(root);
    return 0;
}
