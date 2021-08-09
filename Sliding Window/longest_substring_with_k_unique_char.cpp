#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , int k)
{
	int n = s.length();
	int i = 0;
	int j = 0;
	int res = -1;
	int st;
	int end;

	unordered_map <char , int> mp;

	while(j < n)
	{
		mp[s[j]]++;

		if(mp.size() < k)
		{
			j++;
		}

		else if(mp.size() == k)
		{
			res = max(res , j-i+1);
			st = i;
			end = j;
			j++;
		}

		else
		{
			while(mp.size() > k)
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

	cout << res << endl;
	cout << s.substr(st , end);
}


int main()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	solve(s , k);	
	
}