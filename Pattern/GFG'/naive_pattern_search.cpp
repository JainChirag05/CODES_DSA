#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , string pat)
{
	int n = s.length();
	int m = pat.length();

	for(int i = 0;i<=n-m;i++)
	{
		int j;

		for(j = 0;j<m;j++)
		{
			if(s[i+j] != pat[j])
			{
				break;
			}
		}

		if(j == m)
		{
			cout << i << " ";
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