#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void insert(stack <int> &s , int k)
{
	if(s.size() == 0)
	{
		s.push(k);
		return;
	}

	int temp = s.top();
	s.pop();

	insert(s , k);
	s.push(temp);
}

void reverse(stack <int> &s)
{
	if(s.size() <= 1)
	{
		return;
	}

	int temp = s.top();
	s.pop();

	reverse(s);
	insert(s , temp);
}

int main()
{
	stack <int> s;

	s.push(1);
	s.push(4);
	s.push(3);
	s.push(6);
	s.push(8);

	reverse(s);

	//insert(s , 7);

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}