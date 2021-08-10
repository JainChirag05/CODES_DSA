#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(stack <int> &s , int k)
{
	if(k == 1)
	{
		s.pop();
		return;
	}

	int temp = s.top();
	s.pop();

	solve(s , k-1);
	s.push(temp);
}

void del(stack <int> &s)
{
	if(s.size() == 0)
	{
		return;
	}

	int k = (s.size()/2) + 1;

	solve(s , k);
}

int main()
{
	stack <int> s;

	s.push(1);
	s.push(4);
	s.push(3);
	s.push(6);
	s.push(8);

	del(s);
	del(s);
	

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	
}