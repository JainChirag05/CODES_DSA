#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int price[] , int len[] , int n , int l)
{
	int t[n+1][l+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=l;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=l;j++)
		{
			if(j >= len[i-1])
			{
				int val1 = price[i-1] + t[i][j - len[i-1]];
				int val2 = t[i-1][j];

				t[i][j] = max(val1 , val2);
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][l];

}


int main()
{
	int n;
	cin >> n;

	int price[n];

	for(int i = 0;i<n;i++)
	{
		cin >> price[i];
	}

	int len[n];

	for(int i = 0;i<n;i++)
	{
		len[i] = i+1;
	}

	cout << solve(price , len, n , n);
	
}