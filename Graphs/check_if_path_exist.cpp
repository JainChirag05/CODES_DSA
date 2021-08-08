#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool flag = 0;

void dfs(int n , int m ,int x , int y , vector<vector<int>> &matrix)
{
	if(x < 0 || y < 0 || x >= n || y >= m || matrix[x][y] == 0 || flag == 1)
	{
		return;
	}

	if(matrix[x][y] == 2)
	{
		flag = 1;
		return;
	}

	matrix[x][y] = 0; // marking as visited

	dfs(n , m, x+1 , y ,matrix);
	dfs(n , m, x-1 , y ,matrix);
	dfs(n , m, x , y+1 ,matrix);
	dfs(n , m, x , y-1 ,matrix);
}

int main()
{
	int n,m;
	cin >> n >> m;
	int x;
	int y;

	vector<vector<int>> matrix(n , vector<int>(m , 0));

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin >> matrix[i][j];

			if(matrix[i][j] == 1)
			{
				x = i;
				y = j;
			}
		}
	}

	dfs(n,m,x,y,matrix);

	cout << flag;
	
}