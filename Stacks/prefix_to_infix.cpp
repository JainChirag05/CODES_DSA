#include <bits/stdc++.h>

bool isop(char x)
{
	if(x == '*' || x == '/' || x == '-' || x == '+' || x == '^')
	{
		return true;
	}

	return false;
}

string convert(string s)
{
	stack <string> st;

	int n = s.length();

	for(int i = n-1;i>=0;i--)
	{
		if(isop(s[i]))
		{
			string temp1 = st.top();
			st.pop();

			string temp2 = st.top();
			st.pop();

			string temp = "(" + temp1 + s[i] + temp2 + ")";

			st.push(temp);
		}

		else
		{
			st.push(string(1 , s[i]));
		}
	}

	return st.top();
}