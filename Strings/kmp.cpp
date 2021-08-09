#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<int> prefix_naive(string s)	//O(n^3)
{
	int n = s.length();
	vector<int> prefix(n , 0);

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<=i;j++)
		{
			if(s.substr(0 , j) == s.substr(i-j+1 , j))
			{
				prefix[i] = j;
			}
		}
	}

	return prefix;
}

vector<int> prefix_optimal(string s) // O(n)
{
	int n = s.length();
	vector<int> prefix(n , 0);

	for(int i = 1;i<n;i++)
	{
		int j = prefix[i-1];

		while(j > 0 && s[i] != s[j])
		{
			j = prefix[j-1];
		}

		if(s[i] == s[j])
		{
			j++;
		}

		prefix[i] = j;
	}

	return prefix;
}

void solve(string s , string p)
{
	int n = s.length();
	int m = p.length();

	vector<int> pre = prefix_optimal(p);

	int i = 0;
	int j = 0;

	while(i < n)
	{
		if(p[j] == s[i])
		{
			i++;
			j++;
		}

		if(j == m)
		{
			cout << i-j << " ";
			j = pre[j-1];
		}

		else if(i < n && p[j] != s[i])
		{
			if(j != 0)
			{
				j = pre[j-1];
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

	string p;
	cin >> p;

	solve(s ,p);
	
}