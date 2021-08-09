#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(string a , string b , int x , int y)
{
	int t[x+1][y+1];

	for(int i = 0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=x;i++)
	{
		for(int j = 1;j<=y;j++)
		{
			if((a[i-1] == b[j-1]) && (i != j))
			{
				t[i][j] = 1 + t[i-1][j-1];
			}

			else
			{
				t[i][j] = max(t[i-1][j] , t[i][j-1]);
			}
		}
	}

	return t[x][y];
}

int main()
{
	string a;
	cin >> a;

	int x = a.length();
	cout << solve(a,a,x,x) << endl;
}