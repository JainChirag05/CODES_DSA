#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool isop(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
	{
		return true;
	}

	return false;
}

string solve(string s)
{
	int n = s.length();

	stack <string> st;

	for(int i = 0;i<n;i++)
	{
		if(!isop(s[i]))
		{
			st.push(string(1 , s[i]));
		}

		else
		{
			string temp1 = st.top();
			st.pop();

			string temp2 = st.top();
			st.pop();

			string temp = s[i] + temp2 + temp1;

			st.push(temp);
		}
	}

	return st.top();
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s);
	
}