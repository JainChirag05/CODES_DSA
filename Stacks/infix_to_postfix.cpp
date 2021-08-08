#include <bits/stdc++.h>

using namespace std;

int prec(char c)
{
	if(c == '^')
	{
		return 3;
	}

	else if(c == '*' || c == '/')
	{
		return 2;
	}

	else if(c == '+' || c == '-')
	{
		return 1;
	}

	else
	{
		return -1;
	}
}

string solve(stack <char> st, string s)
{
	int n = s.length();

	string res;

	for(int i = 0;i<n;i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
		{
			res += s[i];
		}

		else if(s[i] == '(')
		{
			st.push(s[i]);
		}

		else if(s[i] == ')')
		{
			while(!st.empty() && st.top() != '(')
			{
				char temp = st.top();
				res += temp;
				st.pop();
			}
			st.pop();
		}

		else
		{
			while(!st.empty() && (prec(st.top()) >= prec(s[i])))
			{
				char temp = st.top();
				res += temp;
				st.pop();
			}

			st.push(s[i]);
		}
	}

	while(!st.empty())
	{
		char temp = st.top();
		res += temp;
		st.pop();
	}

	return res;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		string input;
		cin >> input;
	
		stack <char> s;
	
		cout << solve(s , input);
	}
}
			
