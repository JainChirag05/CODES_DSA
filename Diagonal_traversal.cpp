#include <bits/stdc++.h>

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

vector <int> printdiag(Node *root)
{
	vector<int> ans;
	
	if(root == NULL)
	{
		return ans;
	}
	
	queue <Node*> q;
	
	q.push(root);
	
	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		
		while(temp != NULL)
		{
			if(temp->left != NULL)
			{
				q.push(temp->left);				
			}
			
			ans.push_back(temp->data);
				
			temp = temp->right;
		}
	}
	
	return ans;
}

int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/
 
    vector <int> ans;
    ans = printdiag(root);
    
    int n = ans.size();
    
    for(int i =0;i<n;i++)
    {
		cout << ans[i] << " ";
	}
 
    return 0;
}
