#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.length();
	vector<int> ans(n+1);
	int min = 0;
	int max = n;

	for(int i = 0;i<=n;i++)
	{
		if(s[i] == 'I')
		{
			ans[i] = min;
			min++;
		}

		else
		{
			ans[i] = max;
			max--;
		}
	}

	for(int i = 0;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
}

int main()
{
	string s;
	cin >> s;

	solve(s);	
}