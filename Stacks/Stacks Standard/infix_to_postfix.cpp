#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int prec(char c)
{
	if(c == '^')
	{
		return 3;
	}

	else if(c == '/' || c == '*')
	{
		return 2;
	}

	else if(c == '-' || c == '+')
	{
		return 1;
	}

	return -1;
}

bool isop(char c)
{
	if((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || (c >= '0' && c <= '9'))
	{
		return true;
	}

	return false;
}

string solve(string s)
{
	int n = s.length();

	string ans = "";

	stack <char> st;

	for(int i = 0;i<n;i++)
	{
		if(isop(s[i]))
		{
			ans += s[i];
		}

		else if(s[i] == '(')
		{
			st.push('(');
		}

		else if(s[i] == ')')
		{
			while(st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}

			st.pop();
		}

		else
		{
			while(!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				ans += st.top();
				st.pop();
			}

			st.push(s[i]);
		}
	}

	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}

	return ans;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s);
	
}