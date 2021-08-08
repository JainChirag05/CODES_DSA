#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , int k)
{
	string ans = "";
	stack <char> st;
	int n = s.length();

	for(int i = 0;i<n;i++)
	{
		while(!st.empty() && k > 0 && st.top() > s[i])
		{
			st.pop();
			k--;
		}

		if(!st.empty() || s[i] != '0')
		{
			st.push(s[i]);
		}
	}

	while(!st.empty() && k--) //increasing elements in the num
	{
		st.pop();
	}

	if(st.empty())
	{
		cout << 0 << endl;
	}

	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin() , ans.end());
	
	cout << ans << endl;
}

int main()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	solve(s , k);	
}