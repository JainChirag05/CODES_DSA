#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left, *right;
    node(int x) 
    {
        val = x;
        left = right = NULL;
    }
};

void traversal_trick(node *root) 
{
    //inorder
    stack<pair<node*, int>> S;
    
    S.push({root, 0});
    
    while(!S.empty())
    {
        pair<node*, int> t = S.top();
        node* cur = t.first;
        int state = t.second;
        
        S.pop();

        if(cur == NULL or state == 3) 
        {
			continue;
		}
        
        S.push({cur, state+1});
        
        if (state == 0)
        {
			S.push({cur->left, 0});		//Inorder
			//cout << cur->val << " " ; //Preorder
			//S.push({cur->left, 0});	//Postorder
		}
		
        else if (state == 1)
        {
			cout << cur->val << " " ; //Inorder	
			//S.push({cur->left, 0}); //Preorder
			//S.push({cur->right, 0}); //Postorder
		}
        else if (state == 2)
        { 
			S.push({cur->right, 0});	//Inorder
			//S.push({cur->right, 0});  //Preorder
			//cout << cur->val << " " ; //Postorder
		}
    }
}

int main()
{
    node *root = new node(7); 
    node *t = root;
    root->left = new node(3); root->right = new node(10);
    root->left->left = new node(2); root->left->right = new node(5);
    root->left->left->left = new node(1);
    root->right->left = new node(8); 
    root->right->right = new node(12);
    
    traversal_trick(root);
}
