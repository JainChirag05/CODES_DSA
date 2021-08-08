#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool isop(char c)
{
	if(c == '+' || c == '*' || c == '-' || c == '/')
	{
		return true;
	}

	return false;
}

bool solve(string s)
{
	int n = s.length();
	stack <char> st;

	for(int i = 0;i<n;i++)
	{
		if(isop(s[i]) || s[i] == '(')
		{
			st.push(s[i]);
		}

		else if(s[i] == ')')
		{
			if(st.top() == '(')
			{
				return true;
			}
			
			while(isop(st.top()))
			{
				st.pop();
			}

			st.pop();
		}
	}

	return false;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s);
	
}