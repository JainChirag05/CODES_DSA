#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool valid(int i , int j , int n, int m , vector<vector<int>> grid)
{
	if(i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == 1)
	{
		return true;
	}

	return false;
}

void solve(vector<vector<int>> grid , int n , int m)
{
	queue<pair<int,int>> q;

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(grid[i][j] == 2)
			{
				q.push({i,j});
			}
		}
	}

	int time = -1;

	while(!q.empty())
	{
		int size = q.size();

		while(size--)
		{
			int currX = q.front().first;
			int currY = q.front().second;
			q.pop();

			if(valid(currX + 1 , currY , n , m , grid))
			{
				q.push({currX + 1 , currY});
				grid[currX+1][currY] = 2;
			}

			if(valid(currX - 1 , currY , n , m , grid))
			{
				q.push({currX - 1 , currY});
				grid[currX-1][currY] = 2;
			}

			if(valid(currX , currY+1 , n , m , grid))
			{
				q.push({currX , currY+1});
				grid[currX][currY+1] = 2;
			}

			if(valid(currX , currY-1 , n , m , grid))
			{
				q.push({currX , currY-1});
				grid[currX][currY-1] = 2;
			}
		}

		time++;
	}

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(grid[i][j] == 1)
			{
				cout << -1;
				return;
			}
		}
	}
	cout << time;
}

int main()
{
	int n,m;
	cin >> n >> m;

	vector<vector<int>> grid(n,vector<int>(m,0));

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin >> grid[i][j];
		}
	}

	solve(grid,n,m);	
}