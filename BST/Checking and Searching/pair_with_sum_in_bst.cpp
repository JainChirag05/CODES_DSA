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



//store in inorder and find pair or use DLL

bool solve(Node *root , int sum , unordered_set <int> &s)
{
	if(root == NULL)
	{
		return false;
	}

	if(solve(root->left , sum , s))
	{
		return true;
	}

	if(s.find(sum - root->data) != s.end())
	{
		cout << root->data << " " << sum - root->data << endl;

		return true;
	}

	else
	{
		s.insert(root->data);
	}

	return solve(root->right , sum , s);
}

bool better_space(Node *root , int sum) //O(h) space, worst case is O(n)
{
	stack <Node*> left_traversal;
	stack <Node*> right_traversal;

	Node *temp = root;

	while(temp != NULL)
	{
		left_traversal.push(temp);
		temp = temp->left;
	}

	temp = root;

	while(temp != NULL)
	{
		right_traversal.push(temp);
		temp = temp->right;
	}

	while(!right_traversal.empty() || !left_traversal.empty())
	{
		Node* l = left_traversal.top();
		Node* r = right_traversal.top();

		if(l->data > r->data)
		{
			return false;
		}

		if(l->data + r->data == sum && l->data != r->data)
		{
			return true;
		}

		else if(l->data + r->data > sum)
		{
			right_traversal.pop();
			r = r->left;

			while(r != NULL)
			{
				right_traversal.push(r);
				r = r->right;
			}
		}

		else
		{
			left_traversal.pop();
			l = l->right;

			while(l != NULL)
			{
				left_traversal.push(l);
				l = l->left;
			}
		}
	}

	return false;
}

void final(Node *root , int sum)
{
	unordered_set <int> s;

	//solve(root , sum , s);

	if(!solve(root, sum , s))
	{
		cout << "None" << endl;
	}
}

int main()
{
    Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 10);
 
    int sum = 34;
    final(root, sum);
    cout<< endl;
    cout << better_space(root , sum);
 
    return 0;
}