#include <bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>

using namespace std;

void solve(int n , int m , vector<vector<int>> &matrix , int dest_x , int dest_y)
{
	if(matrix[0][0] == 0 || matrix[dest_x][dest_y] == 0)
	{
		cout << -1;
		return;
	}

	vector<vector<int>> ans(n , vector<int>(m , INT_MAX));

	queue<pi> q;

	q.push({0,0});
	ans[0][0] = 0;

	vector<vector<int>> moves = {{0 , 1},
								 {0 , -1},
								 {1 , 0},
								 {-1 , 0}};

	while(!q.empty())
	{
		pi curr = q.front();
		q.pop();

		int dest_x = curr.first;
		int dest_y = curr.second;

		for(int i = 0;i<4;i++)
		{
			int X = dest_x + moves[i][0];
			int Y = dest_y + moves[i][1];

			if(X >= 0 & Y >=0 && X < n && Y < m && matrix[X][Y] == 1 && ans[X][Y] > ans[dest_x][dest_y] + 1)
			{
				ans[X][Y] = ans[dest_x][dest_y] + 1;
				q.push({X,Y});
			}
		}
	}

	if(ans[dest_x][dest_y] != INT_MAX)
	{
		cout << ans[dest_x][dest_y];
	}

	else
	{
		cout << -1;
	}
}

int main()
{
	int n,m;
	cin >> n >> m;

	vector<vector<int>> matrix(n , vector<int>(m , 0));

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin >> matrix[i][j];
		}
	}

	int dest_x , dest_y;
	cin >> dest_x >> dest_y;

	solve(n,m,matrix,dest_x,dest_y);	
}