#include <bits/stdc++.h>
#define ll long long int

using namespace std;

#define r 3
#define c 3

int min(int x, int y , int z)
{
	if(x < y)
	{
		if(x < z)
		{
			return x;
		}

		else
		{
			return z;
		}
	}

	else
	{
		if(z > x)
		{
			return y;
		}

		else
		{
			return z;
		}
	}
}

int recur(int cost[r][c] , int m , int n)
{
	if(m < 0 || n < 0)
	{
		return -1;
	}

	if(m == 0 && n == 0)
	{
		return cost[m][n];
	}

	return cost[m][n] + min(recur(cost , m-1 , n-1) , recur(cost , m-1 , n) , recur(cost , m , n-1));
}

int top(int cost[r][c] , int m , int n)
{
	int t[m+1][n+1];

	t[0][0] = cost[0][0];

	for(int i = 1;i<=m;i++)
	{
		t[i][0] = t[i-1][0] + cost[i][0];
	}

	for(int j = 1;j<=n;j++)
	{
		t[0][j] = t[0][j-1] + cost[0][j];
	}

	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			t[i][j] = cost[i][j] + min(t[i-1][j-1] , t[i-1][j] , t[i][j-1]);
		}
	}

	return t[m][n];
}

int main()
{
    int cost[r][r] = { { 1, 2, 3 },
                       { 4, 8, 2 },
                       { 1, 5, 3 } };
                        
    cout << recur(cost, 2, 2) << endl;
    cout << top(cost, 2, 2) << endl;
     
    return 0;
}