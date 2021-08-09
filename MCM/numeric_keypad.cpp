#include <bits/stdc++.h>
#define ll long long int

#define r 4
#define col 3

using namespace std;

int dp[10][1005];

int solve(int key[r][col] , int i , int j , int n)
{
	if(n == 1)
	{
		return 1;
	}

	if(dp[key[i][j]][n] != -1)
	{
		return dp[key[i][j]][n];
	}

	long long int a = solve(key , i , j , n-1);

	long long int b = 0 ,c = 0 , d = 0, e = 0;

	if(j-1 >= 0 && key[i][j-1] != -1)
	{
		b = solve(key , i , j-1 , n-1);
	}

	if(j+1 < 3 && key[i][j+1] != -1)
	{
		c = solve(key , i , j+1 , n-1);
	}

	if(i-1 >= 0 && key[i-1][j] != -1)
	{
		d = solve(key , i-1 , j , n-1);
	}

	if(i+1 < 4 && key[i+1][j] != -1)
	{
		e = solve(key , i+1 , j , n-1);
	}

	return dp[key[i][j]][n] = a+b+c+d+e;

}

int main()
{
	int key[r][col] = {{1,2,3},
					 {4,5,6},
					 {7,8,9},
					 {-1,0,-1}};

	int n;
	cin >> n;

	dp[10][n+1];
	memset(dp , -1 , sizeof(dp));

	int ans = 0;

	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<3;j++)
		{
			if(key[i][j] != -1)
			{
				ans += solve(key , i , j , n);
			}
		}
	}

	cout << ans << endl;	
}