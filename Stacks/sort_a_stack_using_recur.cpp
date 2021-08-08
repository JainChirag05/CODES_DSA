#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void insert(stack <int> &s , int k)
{
	if(s.size() == 0 || s.top() > k)
	{
		s.push(k);
		return;
	}

	int temp = s.top();
	s.pop();

	insert(s , k);

	s.push(temp);
	return;
}

void sorting(stack <int> &s)
{
	if(s.size() <= 1)
	{
		return;
	}

	int temp = s.top();
	s.pop();

	sorting(s);
	insert(s , temp);
	return;
}

int main()
{
	stack <int> s;

	s.push(3);
	s.push(6);
	s.push(1);
	s.push(8);
	s.push(10);

	sorting(s);

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	
}