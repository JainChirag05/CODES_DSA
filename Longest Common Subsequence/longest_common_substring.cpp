#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve_optimal(string a , string b, int x , int y)
{
	int t[x+1][y+1];

	for(int i = 0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=x;i++)
	{
		for(int j = 1;j<=y;j++)
		{
			if(a[i-1] == b[j-1])
			{
				t[i][j] = 1 + t[i-1][j-1];
			}

			else
			{
				t[i][j] = 0;
			}
		}
	}

	int ans = INT_MIN;

	for(int i = 0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			ans = max(ans , t[i][j]);
		}
	}

	return ans;
}

int main()
{
	string a;
	cin >> a;
	
	string b;
	cin >> b;

	int x = a.length();
	int y = b.length();

	cout << solve_optimal(a,b,x,y) << endl;
}