#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(string s)
{
	int i = 0;
	int j = 0;
	int n = s.length();
	int res = 0;

	unordered_map <char , int> mp;

	while(j < n)
	{
		mp[s[j]]++;

		if(mp,size() < 2)
		{
			j++;
		}

		else if(mp.size() == 2)
		{
			res = max(res , j-i+1);
			j++;
		}

		else
		{
			while(mp.size() > 2)
			{
				mp[s[i]]--;

				if(mp[s[i]] == 0)
				{
					mp.erase(mp.find(s[i]));
				}

				i++;
			}

			j++;
		}
	}

	return res;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s);
	
}