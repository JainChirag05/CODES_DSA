#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Stack
{
	queue <int> q;

	void push(int x)
	{
		int n = q.size();

		q.push(x);

		for(int i = 0;i<n;i++)
		{
			q.push(q.front());
			q.pop();
		}
	}

	int size()
	{
		return q.size();
	}

	void pop()
	{
		if(q.empty())
		{
			cout << "Empty";
		}

		else
		{
			q.pop();
		}
	}

	int top()
	{
		if(q.empty())
		{
			cout << "Empty";
			exit(0);
		}

		else
		{
			return q.front();
		}
	}

	bool isempty()
	{
		return q.empty();
	}
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
  
    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
  
    cout << "current size: " << s.size()
         << endl;
     }
    