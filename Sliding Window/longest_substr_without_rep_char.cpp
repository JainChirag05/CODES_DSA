#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.length();
	int i = 0;
	int j = 0;
	int st;
	int end;
	int res = -1;

	unordered_map <char , int> mp;

	while(j < n)
	{
		mp[s[j]]++;

		if(mp.size() == j-i+1)
		{
			if(res < j-i+1)
			{
				res = j-i+1;
				st = i;
				end = j;
			}

			j++;
		}

		else if(mp.size() < j-i+1)
		{
			while(mp.size() < j-i+1)
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
	cout << s.substr(st , end-1);
}

void better(string s)
{
	int n = s.length();
	int st = 0;
	int end = 0;
	vector<int> count(300 , 0);

	if(n == 0)
	{
		cout << 0 << endl;
	}

	count[s[0]]++;

	int i = 0;
	int j = 0;
	int ans = 1;

	while(j < n)
	{
		if(count[s[j+1]] == 0)
		{
			j++;
			count[s[j]] = 1;

			if(ans < j-i+1)
			{
				ans = j-i+1;
				st = i;
				end = j;
			}
		}

		else
		{
			count[s[i]]--;
			i++;
		}
	}

	cout << ans << endl;
	cout << s.substr(st , end-1);
}

int main()
{
	string s;
	cin >> s;

	solve(s);
	cout << endl;
	better(s);
	
}