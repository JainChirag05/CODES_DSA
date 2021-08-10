#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void inserting(stack <int> &s , int temp)
{
	if(s.size() == 0 || s.top() <= temp)
	{
		s.push(temp);
		return;
	}

	int val = s.top();
	s.pop();

	inserting(s , temp);

	s.push(val);
}

void sorting(stack <int> &s)
{
	if(s.size() == 1)
	{
		return;
	}

	int temp = s.top();
	s.pop();

	sorting(s);

	inserting(s , temp);

	return;
}

int main()
{
	stack <int> s;

	s.push(9);
	s.push(8);
	s.push(1);
	s.push(6);
	s.push(3);

	

	sorting(s);

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	
}