#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;
}

struct Stack
{
	Node *head;
	Node *mid;
	int count;
}

Stack *newStack()
{
	Stack *st = new Stack();
	st->count = 0;

	return st;
}

void push(Stack *st , int x)
{
	Node *node = new Node();
	node->data = x;

	node->prev = NULL;
	node->next = st->head;

	st->count++;

	if(st->count == 1)
	{
		st->mid = node;
	}

	else
	{
		st->head->prev = node;

		if((st->count)%2 == 0)
		{
			st->mid = st->mid->prev;
		}
	}

	st->head = node;
}

int pop(Stack *st)
{
	if(st->count == 0)
	{
		cout << "Empty";
		return -1;
	}

	Node *head = st->head;

	int val = head->data;
	st->head = head->next;

	if(st->head != NULL)
	{
		st->head->prev = NULL;
	}

	st->count -= 1;

	if((st->count)%2 == 0)
	{
		st->mid = st->mid->next;
	}

	delete(head);

	return val;
}

int find_middle(Stack *st)
{
	if(st->count == 0)
	{
		cout << "Empty";
		return -1;
	}

	return st->mid->data;
}

int del_mid(Stack *st)
{
	if(st->count == 0)
	{
		cout << "Empty";
		return -1;
	}

	int temp = st->mid->data;

	st->mid->prev->next = st->mid->next;
	st->mid->next->prev = st->mid->prev->next;

	delete st->data;

	st->mid = st->mid->next;

	return temp;
}

int main()
{
    /* Let us create a stack using push() operation*/
    Stack* ms = newStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
 
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << find_middle(ms) << endl;
    cout << "Deleted Middle Element is "<<del_mid(ms)<<endl;
    cout << "Middle Element is " << find_middle(ms) << endl;
    return 0;
}
 