#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *link;
};

Node *top = NULL;

bool isempty()
{
	if(top == NULL)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void push(int n)
{
	Node *ptr = new Node();
	ptr->data = n;
	ptr->link = top;
	top = ptr;
}

void pop()
{
	if (isempty())
	{
		cout << "Stack is Empty" << endl;
	}
	
	else
	{
		Node *ptr;
		ptr = top;
		top = top->link;
		free(ptr);
	}	
}

void showtop()
{
	if(isempty())
	{
		cout << "Stack is Empty" << endl;
	}
	
	else
	{
		cout << top->data << endl;
	}
}

void display()
{
	
    if(isempty())
    {
		cout<<"Stack is Empty" << endl;
	}
	
	else
	{
		Node *temp=top;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->link;
		}
		
	cout<<"\n";
	}
 }

int main()
{
	int choice, flag=1, value;
	
	while( flag == 1)
	{
		cout<<"\n1.PUSH 2.POP 3.SHOW_TOP 4.DISPLAY_STACK 5.EXIT\n";
		cin>>choice;
		
		switch (choice)
		{
			case 1: cout<<"Enter Value:\n";
			cin>>value;
			push(value);
			break;
			
			case 2: pop();
			break;
			
			case 3: showtop();
			break;
			
			case 4: display();
			break;
			
			case 5: flag = 0;
			break;
		}
	}
 
}


