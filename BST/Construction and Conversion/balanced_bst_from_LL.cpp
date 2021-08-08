#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct List
{
	int val;
	List *next;
};

void push(List** head_ref, int new_data) 
{ 
    /* allocate node */
    List* new_node = new List();
      
    /* put in the data */
    new_node->val = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

void printList(List *node) 
{ 
    while(node!=NULL) 
    { 
        cout << node->val << " "; 
        node = node->next; 
    } 
}


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

void preOrder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
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

//M1 -- Convert LL to vector then convert array to bst

List *middle(List *head)
{
	List *prev = head, *slow = head, *fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if(prev != NULL)
	{
		prev->next = NULL;
	}

	return slow;
}

Node *create(List *head)
{
	if(head == NULL)
	{
		return NULL;
	}

	List *mid = middle(head);

	Node *root = newNode(mid->val);

	if(head == mid)
	{
		return root;
	}

	root->left = create(head);
	root->right = create(mid->next);

	return root;
}

int main() 
{ 
    
    List* head = NULL; 
  
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    cout<<"Given Linked List "; 
    printList(head); 
  
    Node *root = create(head); 
    cout<<"\nPreOrder Traversal of constructed BST "; 
    preOrder(root); 
  
    return 0; 
} 