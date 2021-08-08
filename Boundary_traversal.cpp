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
	temp->left = temp->right = NULL;
	
	temp->data = num;
	
	return temp;	
}

void lefttree(Node *root , vector<int> &res)
{
	if(root == NULL)
	{
		return;
	}
	
	if(root->left != NULL)
	{
		res.push_back(root->data);
		lefttree(root->left , res);
	}
	
	else if(root->right != NULL)
	{
		res.push_back(root->data);
		lefttree(root->right , res);
	}
}

void leaf(Node *root , vector <int> &res)
{
	if(root == NULL)
	{
		return;
	}
	
	leaf(root->left , res);
	
	if(root->left == NULL && root->right == NULL)
	{
		res.push_back(root->data);
	}
	
	leaf(root->right , res);
}

void righttree(Node *root , vector<int> &res)
{
	if(root == NULL)
	{
		return;
	}
	
	if(root->right != NULL)
	{
		righttree(root->right , res);
		res.push_back(root->data);
	}
	
	else if(root->left != NULL)
	{
		righttree(root->left , res);
		res.push_back(root->data);
	}
}

vector <int> print(Node *root)
{
	vector <int> ans;
	ans.push_back(root->data);
	
    lefttree(root->left , ans);
    leaf(root , ans);
    righttree(root->right , ans);
    
    return ans;
}

int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25); 
    
    vector<int> res;
    
    res = print(root);
    
    int n = res.size();
    
    for(int i =0;i<n;i++)
    {
		cout << res[i] << " ";   
    }
    
    return 0;
}
