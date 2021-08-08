#include <bits/stdc++.h>
#define ll long long int

using namespace std;

stack <int> st;
stack <int> s;

void push(int x)
{
	st.push(x);

	if(s.empty())
	{
		s.push(x);
	}

	int smol = min(s.top() , x);

	else
	{
		s.push(smol);
	}
}

void pop()
{
	st.pop();
	s.pop();
}

int minstack()
{
	if(s.size() == 0)
	{
		return -1;
	}

	return s.top();
}

