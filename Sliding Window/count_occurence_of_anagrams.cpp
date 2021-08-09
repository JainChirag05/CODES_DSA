#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , string pat)
{
	vector <int> res;
	unordered_map <char , int> mp;

	for(auto it : pat)
	{
		mp[it]++;
	}

	int count = mp.size();

	int k = pat.length();

	int i = 0;
	int j = 0;
	int ans = 0;

	while(j < s.length())
	{
		if(mp.find(s[j]) != mp.end())
		{
			mp[s[j]]--;

			if(mp[s[j]] == 0)
			{
				count--;
			}
		}

		if(j-i+1 < k)
		{
			j++;
		}

		else if(j-i+1 == k)
		{
			if(count == 0)
			{
				ans++;
			}

			if(mp.find(s[i]) != mp.end())
			{
				mp[s[i]]++;

				if(mp[s[i]] == 1)
				{
					count++;
				}
			}

			i++;
			j++;
		}

	}

	

	cout << endl;

	cout << ans;
}

int main()
{
	string s;
	cin >> s;

	string pat;
	cin >> pat;

	solve(s , pat);
	
}