#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(stack <int> &s)
{
	if(s.size() == 1)
	{
		cout << s.top();
		return;
	}

	stack <int> temp;

	while(!s.empty())
	{
		int x = s.top();
		s.pop();

		while(!temp.empty() && temp.top() > x)
		{
			int var = temp.top();
			temp.pop();
			s.push(var);
		}

		temp.push(x);
	}

	while(!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	}
}

int main()
{
	stack <int> s;

	s.push(5);
	s.push(4);
	s.push(0);
	s.push(1);
	s.push(8);
	s.push(3);

	solve(s);
	
}