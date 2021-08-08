#include <bits/stdc++.h>

#define size 5

int stackarr[size];
int top = -1;

using namespace std;

bool isempty()
{
	if (top == -1)
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
	if(top == size-1)
	{
		cout << "Stack is Full" << endl;
	}
	
	else
	{
		top++;
		stackarr[top] = n;
	}
}

void pop()
{
	if(top == -1)
	{
		cout << "Stack is empty" << endl;
	}
	
	else
	{
		top--;
	}
}

void showtop()
{
	if(top == -1)
	{
		cout << "Stack is Empty" << endl;
	}
	
	else
	{
		cout << stackarr[top] << endl;
	}
}

void display()
{
	if(isempty())
	{
		cout << "Stack is Empty" << endl;
	}
	
	else
	{
		for(int i = 0;i<=top;i++)
		{
			cout << stackarr[i] << " ";
		}
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
		


