#include <bits/stdc++.h>
#define ll long long int
#define n 8

using namespace std;

bool valid(int arr[n+1][n+1] , int row , int col)
{
	if(row >=0 && row < n && col >= 0 && col < n && arr[row][col] == -1)
	{
		return true;
	}

	return false;
}

bool solve(int arr[n+1][n+1] , int row , int col , int count , int xmove[] , int ymove[])
{
	if(count == n*n)
	{
		return true;
	}

	int k;

	for(k = 0;k<n;k++)
	{
		int next_row = row + xmove[k];
		int next_col = col + ymove[k];

		if(valid(arr , next_row , next_col))
		{
			arr[next_row][next_col] = count;

			if(solve(arr , next_row , next_col , count+1 , xmove , ymove))
			{
				return true;
			}

			arr[next_row][next_col] = -1;
		}
	}

	return false;
}

int final()
{
	int arr[n+1][n+1];

	int row , col;

	for(row = 0;row <= n; row++)
	{
		for(col = 0;col <= n;col++)
		{
			arr[row][col] = -1;
		}

		cout << endl;
	}

	int xmove[] = {2 , 1 , -1 , -2 , -2 , -1 , 1 , 2};
	int ymove[] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};

	arr[0][0] = 0;

	if(solve(arr , 1 , 1 , 1 , xmove , ymove))
	{
		for(row = 1;row <= n; row++)
		{
			for(col = 1;col <= n;col++)
			{
				cout << arr[row][col] << " ";
			}

			cout << endl;
		}
	}	
}



