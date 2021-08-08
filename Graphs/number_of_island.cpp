#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void dfs(int i , int j , vector<int> adj[] , int vis[][501] , int n , int m)
{
	if(i >= n || i < 0 || j >= m || j < 0)
	{
		return;
	}

	if(vis[i][j] == 0)
	{
		vis[i][j] = 1;

		dfs(i+1 , j , adj , vis , n , m);
		dfs(i-1 , j , adj , vis , n , m);
		dfs(i+1 , j+1 , adj , vis , n , m);
		dfs(i-1 , j-1 , adj , vis , n , m);
		dfs(i+1 , j-1 , adj , vis , n , m);
		dfs(i-1 , j+1 , adj , vis , n , m);
		dfs(i , j+1 , adj , vis , n , m);
		dfs(i , j-1 , adj , vis , n , m);
	}
}


int solve(vector<int> adj[] , int n , int m)
{
	int vis[501][501] = {0};

	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(vis[i][j] == 0 && adj[i][j] == 1)
			{
				dfs(i , j , adj , vis , n , m);
				ans++;
			}
		}
	}

	return ans;
}