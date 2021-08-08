#include <bits/stdc++.h>
#define ll long long int
#define max 100

using namespace std;

struct TwoStacks
{
	int arr[max];
	int top1 = -1;
	int top2 = max;

	void push1(int x)
	{
		if(top2 - top1 > 1)
		{
			top1++;
			arr[top1] = x;
		}

		else
		{
			cout << "Full";
			exit(1);
		}
	}

	void push2(int x)
	{
		if(top2 - top1 > 1)
		{
			top2++;
			arr[top2] = x;
		}

		else
		{
			cout << "Full";
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
			cout << "Empty";
			exit(0);
		}
	}

	int pop2()
	{
		if(top2 <= max-1)
		{
			int x = arr[top2];
			top2++;
			return x;
		}

		else
		{
			cout << "Empty";
			exit(0);
		}
	}

};

int main()
{
	TwoStacks ts;
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
	