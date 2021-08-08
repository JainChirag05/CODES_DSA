#include <bits/stdc++.h>
#define ll long long int
using namespace std;


vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        
        if(root == NULL)
        {
            return ans;
        }
        
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> v;
            
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                v.push_back(temp->val);
                
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }   
            }
            
            ans.push_back(v);                       
        }
        return ans;        
    }
int main()
{
	
}