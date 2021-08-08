#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	char data;
	Node *left;
	Node *right;
};

Node *newNode(char val)
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

Node* build(vector<char>& inorder, unordered_map<char,int>& mp,int st, int end)
{
    if (st > end)
  	{
    	return NULL;
    }

    // find node with minimum index in level-order traversal
    // That would be the root node of inorder[start, end]
    int idx = st;

    for (int j = st + 1; j <= end; j++)
    {
        if (mp[inorder[j]] < mp[inorder[idx]])
        {
            idx = j;
        }
    }
    
    Node* node = newNode(inorder[idx]);

    if (st == end)
    {
        return node;
    }

    // recursively construct the left and right subtree
    node->left = build(inorder, mp, st, idx - 1);
    node->right = build(inorder,  mp, idx + 1, end);

    return node;
}

int main()
{
    vector<char> inorder = {'H','D','P','L','A','Z','C','E'};
    vector<char> levelorder = {'A','D','Z','H','L','C','P','E'};

    // construct a value-to-index map for levelorder traversal
    unordered_map<char,int> mp;
    for (int i=0; i < levelorder.size(); i++)
        mp[levelorder[i]] = i;

    Node *root = build(inorder, mp, 0, inorder.size()-1);
    
    cout << "Tree constructed" << endl;
    cout << "Inorder traversal of the constructed tree: ";
    inorder(root);
    cout << endl;
}
