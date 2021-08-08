#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Queue1
{
	stack <int> s1 , s2;

	void push(int x)
	{
		s1.push(x);
	}

	int pop()
	{
		if(s1.empty() && s2.empty())
		{
			cout << "Empty";
			exit(0);
		}

		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		int ans = s2.top();
		s2.pop();

		return ans;
	}
};

int main()
{
    Queue1 q;
    q.push(1);
    q.push(2);
    q.push(3);
 
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
 
    return 0;
}