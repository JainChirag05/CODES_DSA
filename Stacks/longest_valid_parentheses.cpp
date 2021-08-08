#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.length();
	int ans = -1;

	stack<char> st;
	st.push(-1);

	for(int i = 0;i<n;i++)
	{
		if(s[i] == '(')
		{
			st.push(i);
		}

		else
		{
			st.pop();

			if(st.empty())
			{
				st.push(i);
			}

			else
			{
				ans = max(ans , i - st.top());
			}
		}
	}

	cout << ans;
}

int main()
{
	string s;
	cin >> s;

	solve(s);	
}