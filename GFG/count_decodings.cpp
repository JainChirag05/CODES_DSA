#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve1(string s)
{
	int n = s.length();
	int count[n+1];

	count[0] = 1;
	count[1] = 1;

	if(s[0] == '0')
	{
		return 0;
	}

	for(int i = 2;i<=n;i++)
	{
		count[i] = 0;

		if(s[i-1] > '0')
		{
			count[i] = count[i-1];
		}

		if(s[i-2] <= '2' && s[i-1] <= '6')
		{
			count[i] += count[i-2];
		}
	}

	return count[n];
}

int solve2(string s)
{
	int n = s.length();
	int count1 = 1;
	int count2 = 1;

	if(n == 0 || s[0] == '0')
	{
		return 0;
	}

	if(n == 1)
	{
		return 1;
	}

	for(int i = 1;i<n;i++)
	{
		int d = s[i] - '0';
		int dd = (s[i-1] - '0')*10 + d;

		int count = 0;

		if(d > 0)
		{
			count += count2;
		}

		if(dd >= 10 && dd <= 26)
		{
			count += count1;
		}

		count1 = count2;
		count2 = count;
	}

	return count2;
}

int main()
{
	string s;
	cin >> s;

	cout << solve1(s) << endl;
	cout << solve2(s);	
}