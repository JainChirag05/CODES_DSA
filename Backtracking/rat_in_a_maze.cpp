#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool valid(vector<vector<int>> arr , int x , int y , int n)
{
	if(x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1)
	{
		return true;
	}

	return false;
}

bool solve(vector<vector<int>> &arr , int x , int y , int n, vector<vector<int>>& sol)
{
	if(x == (n-1) && y == (n-1) && arr[x][y] == 1)
	{
		sol[x][y] == 1;		
		return true;
	}

	if(valid(arr , x , y , n))
	{
		if(sol[x][y] == 1)
		{
			return false;
		}

		sol[x][y] == 1;

		if(solve(arr , x+1 , y , n , sol))
		{
			return true;
		}

		if(solve(arr , x , y+1 , n , sol))
		{
			return true;
		}

		if(solve(arr , x-1 , y , n , sol))
		{
			return true;
		}

		if(solve(arr , x , y-1 , n , sol))
		{
			return true;
		}

		sol[x][y] == 0;

		return false;
	}

	return false;
}

bool final(vector<vector<int>> &arr)
{
	int n = arr.size();
	vector<vector<int>> sol(n , vector<int>(n,0));

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			sol[i][j] = 0;
		}
	}

	if(solve(arr , 0 , 0 , n , sol))
	{
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				cout << sol[i][j] << " ";
			}

			cout << endl;
		}
	}

	else
	{
		cout << "Not Possible";
		return false;
	}

	return true;		
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> arr(n , vector<int>(n,0));

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}

	final(arr);
}