#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.length();
	map<int,int> mp;
	stack <char> st;

	for(int i = 0;i<n;i++)
	{
		mp[s[i]]++;
	}

	vector<bool> vis(26 , 0);

	for(int i = 0;i<n;i++)
	{
		mp[s[i]]--;

		if(vis[s[i] - 'a'])
		{
			continue;
		}

		while(!st.empty() && st.top() > s[i] && mp[st.top()] > 0)
		{
			vis[st.top() - 'a'] = 0;
			st.pop();
		}

		st.push(s[i]);
		vis[s[i] - 'a'] = 1;
	}

	string ans = "";

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

	solve(s);
	
}