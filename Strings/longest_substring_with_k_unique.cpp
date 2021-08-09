#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , int k)
{
	int n = s.length();
	unordered_map<char,int> mp;
	int len = INT_MIN;
	int st = 0;

	int i = 0;
	int j = 0;

	while(j < n)
	{
		mp[s[j]]++;

		if(mp.size() < k)
		{
			j++;
		}

		else if(mp.size() == k)
		{
			if(len < j-i+1)
			{
				len = j-i+1;
				st = i;
			}

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

	string res = "";

	if(len != INT_MAX)
	{
		cout << len << endl;
		res += s.substr(st ,len);
		cout << res;
	}

	else
	{
		cout << "None";
	}
}

int main()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	solve(s,k);	
}