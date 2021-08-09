#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.size();
	int ans = 0;
	int i = 0;
	int j = 0;

	unordered_map<char , int> mp;

	while(j < n)
	{
		if(i < n && mp[s[i]] == 0)
		{
			mp[s[i]]++;
			ans += i-j+1;
			i++;
		}

		else
		{
			mp[s[j]]--;
			j++;
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