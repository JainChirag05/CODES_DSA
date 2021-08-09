#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<int> prefix_fun(string s) //O(n)
{
	int n = s.length();

	vector <int> pref(n , 0);

	for(int i = 1;i<n;i++)
	{
		int j = pref[i-1];

		while(j> 0 && s[i] != s[j])
		{
			j = pref[j-1];
		}

		if(s[j] == s[i])
		{
			j++;
		}

		pref[i] = j;
	}

	return pref;
}

void solve(string s , string pat)
{
	vector<int> res = prefix_fun(pat);

	int n = s.length();
	int m = pat.length();

	int i = 0;
	int j = 0;

	while(i < n)
	{
		if(pat[j] == s[i])
		{
			i++;
			j++;
		}

		if(j == m)
		{
			cout << i-j << " ";

			j = res[j-1];
		}

		else if(i < n && pat[j] != s[i])
		{
			if(j != 0)
			{
				j = res[j-1];
			}

			else
			{
				i++;
			}
		}
	}
}

int main()
{
	string s;
	cin >> s;

	string pat;
	cin >> pat;

	solve(s , pat);
}
	
