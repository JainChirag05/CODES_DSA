#include <bits/stdc++.h>
#define ll long long int

#define max 100

using namespace std;

struct Stack
{
	int arr[max];
	int top = -1;

	bool isempty()
	{
		if(top == -1)
		{
			return true;
		}

		return false;
	}

	bool isfull()
	{
		if(top == max - 1)
		{
			return true;
		}

		return false;
	}

	void pop()
	{
		if(isempty())
		{
			abort();
		}

		else
		{
			int ans = arr[top];
			top--;
			//return ans;
		}
	}

	int top_ele()
	{
		if(isempty())
		{
			abort();
		}

		else
		{
			return arr[top];
		}
	}

	void push(int x)
	{
		if(isfull())
		{
			abort();
		}

		else
		{
			top++;
			arr[top] = x;
		}
	}
};

struct SpecialStack
{
	Stack s1;
	Stack s2;

	void push2(int x)
	{
		int mini;

		if(s1.isempty() && s2.isempty())
		{
			s1.push(x);
			s2.push(x);
			mini = x;
		}

		else
		{
			s1.push(x);
			mini = min(s2.top_ele() , x);
			s2.push(mini);
		}
	}

	int pop2()
	{
		int x = s1.top_ele();
		s1.pop();
		s2.pop();

		return x;
	}

	int getmin()
	{
		int ans = s2.top_ele();
		s2.pop();

		return ans;
	}
};

int main()
{
    SpecialStack s;
    s.push2(10);
    s.push2(20);
    s.push2(30);
    cout << s.getmin() << endl;
    s.push2(5);
    cout << s.getmin();
    return 0;
}