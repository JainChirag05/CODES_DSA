#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void push(Node **head,int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void store(Node *h1 , Node *h2 , unordered_map<int,int>& m)
{
	Node *t1 = h1;
	Node *t2 = h2;

	while(t1 != NULL || t2 != NULL)
	{
		if(t1 != NULL)
		{
			m[t1->data]++;
			t1 = t1->next;
		}

		if(t2 != NULL)
		{
			m[t2->data]++;
			t2 = t2->next;
		}
	}
}

Node *unio(unordered_map<int,int> m)
{
	Node *res = NULL;

	for(auto it = m.begin(); it != m.end();it++)
	{
		push(&res , it->first);
	}

	return res;
}

Node *intersect(unordered_map<int,int> m)
{
	Node *res = NULL;

	for(auto it = m.begin(); it != m.end();it++)
	{
		if(it->second == 2)
		{
			push(&res , it->first);
		}
	}

	return res;
}

void printlist(Node *temp)
{
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void printfinal(Node *h1 , Node *h2)
{
	unordered_map<int,int> ans;

	store(h1 , h2 , ans);

	Node *unionhead = unio(ans);
	Node *intersecthead = intersect(ans);

	printlist(unionhead);
	cout << endl;
	printlist(intersecthead); 
}

int main()
{
	Node* head1 = NULL;
    Node* head2 = NULL;
  
    /* create a linked list 11->10->15->4->20 */
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);
  
    /* create a linked list 8->4->2->10 */
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 5);
    push(&head2, 6);

    printlist(head1);
    cout << endl;
    printlist(head2);
    cout << endl;
	printfinal(head1 , head2);
}