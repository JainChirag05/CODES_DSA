#include <bits/stdc++.h>
using namespace std;


//method 1 -- divide array into 2 halves but there is wastage of space
//this method might result in an overflow when more than n/2 elements are passed in stack 1

//Better method -- Use 2 pointers

class twostack
{
	int *arr;
	int size;
	int top1 , top2;

public:
	twostack(int n)
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	void push1(int x)
	{
		if(top1 < top2 - 1)
		{
			top1++;
			arr[top1] = x;
		}

		else
		{
			cout << "Overflow" << endl;
			exit(1);
		}
	}

	void push2(int x)
	{
		if(top1 < top2 - 1)
		{
			top2--;
			arr[top2] = x;
		}

		else
		{
			cout << "Overflow" << endl;
			exit(1);
		}
	}

	int pop1()
	{
		if(top1 >= 0)
		{
			int x = arr[top1];
			top1--;
			return x;
		}

		else
		{
			cout << "Overflow" << endl;
			exit(1);
		}
	}

	int pop2()
	{
		if(top2 < size)
		{
			int x = arr[top2];
			top2++;
			return x;
		}

		else
		{
			cout << "Overflow" << endl;
			exit(1);
		}
	}
};

int main()
{
    twostack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2();
    return 0;
}

