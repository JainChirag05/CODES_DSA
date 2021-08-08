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

string check(Node *n1 , Node *n2)
{
	stack <Node*> s1 , s2;

	while(1)
	{
		while(n1 && n2)
		{
			if(n1->data != n2->data)
			{
				return "No";
			}

			s1.push(n1);
			s2.push(n2);
			n1 = n1->left;
			n2 = n2->right;
		}

		if(!(n1 == NULL && n2 == NULL))
		{
			return "No";
		}

		if(!s1.empty() && !s2.empty())
		{
			n1 = s1.top();
			s1.pop();
			n2 = s2.top();
			s2.pop();

			n1 = n1->right;
			n2 = n2->left;
		}

		else
		{
			break;
		}
	}

	return "Yes";
}

int main()
{
    // 1st binary tree formation
    Node *root1 = newNode(1);            /*         1          */                      
    root1->left = newNode(3);            /*       /   \        */
    root1->right = newNode(2);           /*      3     2       */ 
    root1->right->left = newNode(5);     /*          /   \     */  
    root1->right->right = newNode(4);    /*         5     4    */
      
    // 2nd binary tree formation    
    Node *root2 = newNode(1);            /*         1          */                      
    root2->left = newNode(2);            /*       /   \        */
    root2->right = newNode(3);           /*      2     3       */
    root2->left->left = newNode(4);      /*    /   \           */
    root2->left->right = newNode(5);     /*   4    5           */
          
    cout << check(root1, root2);
    return 0;
} 