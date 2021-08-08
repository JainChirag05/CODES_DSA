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

void solve(Node *root , int k , map<int,vector<int>> &m)
{
    if(root == NULL)
    {
	    return;
    }
       
    solve(root->left , k-1, m);
    m[k].push_back(root->data);
    solve(root->right , k+1 , m);
}
    
void verticalOrder(Node *root)
{
    map<int,vector<int>> m;
    vector<int> ans;
    
    solve(root , 0 , m);
     
    for(auto i = m.begin(); i != m.end();i++)
    {
        for(int j = 0;j<i->second.size();j++)
        {
            cout << i->second[j] << " ";
        }

        cout << endl;
    }
     
}

void in_apperance(Node *root) //(top to bottom)
{
    map<int,vector<int>> mp;
    vector<vector<int>> ans;
    int d = 0;

    if(root == NULL)
    {
        return;
    }

    queue<pair<Node* , int>> q;
    q.push({root , d});

    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();

        d = temp.second;
        Node *node = temp.first;

        mp[d].push_back(node->data);

        if(node->left)
        {
            q.push({node->left , d-1});
        }

        if(node->right)
        {
            q.push({node->right , d+1});
        }
    }

    for(auto i = mp.begin(); i != mp.end();i++)
    {
        for(int j = 0;j<i->second.size();j++)
        {
            cout << i->second[j] << " ";
        }

        cout << endl;
    }

}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is ";
    cout << endl;
    verticalOrder(root);
    cout << endl;
    in_apperance(root);
    return 0;
}