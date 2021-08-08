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

void inorder(Node * root, vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-5);
        return ;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void preorder(Node * root, vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-5);
        return ;
    }

    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}

bool check( vector<int> parent ,vector<int> child)
{
    string s1="";
    string s2="";
    
    for(long long int i=0;i<parent.size();i++)
    {
        s1+= to_string(parent[i]);
    }
        
    for(long long int i=0;i<child.size();i++)
    {
        s2+= to_string(child[i]);
    }
     
    if( s1.find(s2) != -1)
    {
        return true;
    }
     
    return false;
}

bool final(Node*  T1 ,Node * T2)
{
    vector<int> int1;
    vector<int> int2;
    vector<int> pret1;
    vector<int> pret2;
 
    inorder(T1,int1);
    inorder(T2,int2);
    preorder(T1,pret1);
    preorder(T2,pret2);
     
    return check(int1,int2) && check(pret1,pret2); 
}

//O(mn) solution

bool areIdentical(Node * root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }   
 
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
 
    return (root1->data == root2->data && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
}
 
bool isSubtree(Node *T, Node *S)
{
    
    if (S == NULL)
    {
       return true;
    }
 
    if (T == NULL)
    {
        return false;
    }  
 
    
    if (areIdentical(T, S))
    {
        return true;
    }  
 
    return isSubtree(T->left, S) || isSubtree(T->right, S);
} 

int main()
{
    Node* T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node* S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (final(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";

    cout << endl;

    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
 
    return 0;
}
