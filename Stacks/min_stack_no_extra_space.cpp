#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int ans;

int getmin()
{
	if(st.size() == 0)
	{
		return -1;
	}

	return ans;
}

void push(int x)
{
	if(st.empty())
	{
		st.push(x);
		ans = x;
	}

	else
	{
		if(x >= ans)
		{
			st.push(x);
		}

		else
		{
			st.push(2*x - ans);
			ans = x;
		}
	}
}

void pop()
{
	if(st.empty())
	{
		return -1;
	}

	else
	{
		if(st.top() > ans)
		{
			st.pop();
		}

		else
		{
			ans = 2*ans - st.top();
			st.pop();
		}
	}
}

int top()
{
	if(st.empty())
	{
		return -1;
	}

	if(st.top() >= ans)
	{
		return st.top();
	}

	else
	{
		return ans;
	}
}

int main()
{
	
}