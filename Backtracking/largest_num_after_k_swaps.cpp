#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string ans;

void solve(string s , int k)
{
	if(k == 0)
	{
		return;
	}

	int n = s.length();

	for(int i = 0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(s[j] > s[i])
			{
				swap(s[j] , s[i]);
				ans = max(ans , s);
				solve(s , k-1);
				swap(s[j] , s[i]);
			}
		}
	}
}

int main()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	solve(s,k);	

	cout << ans;
}