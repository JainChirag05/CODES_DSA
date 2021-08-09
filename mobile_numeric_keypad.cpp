#include <bits/stdc++.h>
#define ll long long int

using namespace std;

long long int dp[10][1005];

int arr[4][3] = {{1,2,3},
				 {4,5,6},
				 {7,8,9},
				 {-1,0,-1}};

long long int solve(int i , int j , int n)
{
	if(n == 1)
	{
		return 1;
	}

	if(dp[arr[i][j]][n] != -1)
	{
		return dp[arr[i][j]][n];
	}

	long long int a = solve(i,j,n-1);

	long long int b,c,d,e;

	b=0;
	c=0;
	d=0;
	e=0;

	if(j-1>=0 && arr[i][j-1] != -1)
	{
		b = solve(i , j-1 , n-1);
	}

	if(j+1 < 3 && arr[i][j+1] != -1)
	{
		c = solve(i , j+1 , n-1);
	}

	if(i-1>=0 && arr[i-1][j] != -1)
	{
		d = solve(i-1 , j , n-1);
	}

	if(i+1 < 4 && arr[i+1][j] != -1)
	{
		e = solve(i+1 , j , n-1);
	}

	return dp[arr[i][j]][n] = a+b+c+d+e;
}


int main()
{
	int n;
	cin >> n;

	dp[10][n+1];
	memset(dp , -1 , sizeof(dp));

	long long int ans = 0;

	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<3;j++)
		{
			if(arr[i][j] != -1)
			{
				ans += solve(i,j,n);
			}
		}
	}

	cout << ans << endl;
	
}