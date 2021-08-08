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

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	queue <Node*> q;
	q.push(root);

	int sum = 0;
	int ans = INT_MIN;

	while(!q.empty())
	{
		sum = 0;
		int n = q.size();

		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			sum += temp->data;

			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}

		ans = max(sum , ans);
	}

	return ans;
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
 
    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    cout << "Maximum level sum is " << solve(root)
         << endl;
    return 0;
}