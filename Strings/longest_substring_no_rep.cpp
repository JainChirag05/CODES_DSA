#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//sliding window technique

int solve(string s)
{
	int n = s.length();

	if(n <= 1)
	{
		return n;
	}

	unordered_map<char,int> mp;

	int i = 0;
	int j = 0;
	int ans = 0;

	while(j < n)
	{
		if(mp[s[j]] == 0)
		{
			ans = max(ans , j-i+1);
			mp[s[j]]++;
			j++;
		}

		else
		{
			mp[s[i]]--;
			i++;
		}
	}

	return ans;
}


int main()
{
	string s;
	cin >> s;

	cout << solve(s);
}