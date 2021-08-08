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

vector <int> solve_right(Node *root)
{
	vector<int> ans;

	if(root == NULL)
	{
		return ans;
	}

	queue <Node*> q;
	q.push(root);

	int flag = 1;

	while(!q.empty())
	{
		vector <int> temp;
		int n = q.size();

		while(n--)
		{
			Node *node = q.front();
			temp.push_back(node->data);
			q.pop();			

			if(node->left)
			{
				q.push(node->left);
			}

			if(node->right)
			{
				q.push(node->right);
			}
		}

		if(flag%2 == 0)
		{
			reverse(temp.begin() , temp.end());
		}

		for(int i = 0;i<temp.size();i++)
		{
			ans.push_back(temp[i]);
		}

		flag =! flag;
	}

	return ans;
}

vector <int> solve_left(Node *root)
{
	vector<int> ans;

	if(root == NULL)
	{
		return ans;
	}

	queue <Node*> q;
	q.push(root);

	int flag = 1;

	while(!q.empty())
	{
		vector <int> temp;
		int n = q.size();

		while(n--)
		{
			Node *node = q.front();
			temp.push_back(node->data);
			q.pop();			

			if(node->left)
			{
				q.push(node->left);
			}

			if(node->right)
			{
				q.push(node->right);
			}
		}

		if(flag%2 != 0)
		{
			reverse(temp.begin() , temp.end());
		}

		for(int i = 0;i<temp.size();i++)
		{
			ans.push_back(temp[i]);
		}

		flag =! flag;
	}

	return ans;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of " 
           "binary tree is \n");
             
    vector <int> res_left = solve_left(root);

    for(int i = 0;i<res_left.size();i++)
    {
    	cout << res_left[i] << " ";
    }

    cout << endl;
    vector <int> res_right = solve_right(root);

    for(int i = 0;i<res_right.size();i++)
    {
    	cout << res_right[i] << " ";
    }

  
    return 0;
}