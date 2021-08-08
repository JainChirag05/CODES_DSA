#include <bits/stdc++.h>
#define ll long long int
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

void ans(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	stack <Node*> s;
	s.push(root);

	if(root->left != NULL)
	{
		s.push(root->right);
		s.push(root->left);
	}

	if(root->left->left == NULL)
	{
		while(!s.empty())
		{
			cout << s.top()->data << " ";
			s.pop();
		}

	}

	else
	{
		queue <Node*> q;

		q.push(root->left);
		q.push(root->right);

		Node *ptr1 = NULL , *ptr2 = NULL;

		while(!q.empty())
		{
			ptr1 = q.front();
			q.pop();

			ptr2 = q.front();
			q.pop();

			s.push(ptr2->left);
			s.push(ptr1->right);
			s.push(ptr2->right);
			s.push(ptr1->left);

			if(ptr1->left->left != NULL)
			{
				q.push(ptr1->right);
				q.push(ptr2->left);
				q.push(ptr1->left);
				q.push(ptr2->right);
			}
		}

		while(!s.empty())
		{
			cout << s.top()->data << " ";
			s.pop();
		}
	}


}


int main()
{
    Node* root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
  
    cout << "Specific Level Order traversal of binary tree is \n";
    ans(root);
  
    return 0;
}