#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.length();

	for(int i = 0;i<n;i++)
	{
		if(s[i] == '0')
		{
			char c = -1;
			s[i] = c;
		}
	}

	int st = 0;
	int end = 0;
	int ans = 0;
	int sum = s[0] - '0';

	while(st < n && end < n)
	{
		end++;

		if(sum <= 0)
		{
			if(end >= st)
			{
				ans += end - st;
			}

			if(end < n)
			{
				sum += (s[end] - '0');
			}
		}

		else
		{
			sum -= (s[st] - '0');
			st++;
		}
	}

	cout << n*(n+1)/2 - ans << endl;
}

int main()
{
	string s;
	cin >> s;

	solve(s);
	
}