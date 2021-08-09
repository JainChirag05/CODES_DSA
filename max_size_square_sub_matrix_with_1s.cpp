#include <bits/stdc++.h>
#define ll long long int

#define r 6
#define c 5

using namespace std;

void solve(int arr[r][c])
{
	int t[r+1][c+1];

	for(int i = 0;i<=r;i++)
	{
		t[i][0] = arr[i][0];
	}

	for(int j = 0;j<=c;j++)
	{
		t[0][j] = arr[0][j];
	}

	for(int i = 1;i<=r;i++)
	{
		for(int j = 1;j<=c;j++)
		{
			if(arr[i][j] == 1)
			{
				t[i][j] = min(t[i][j-1] , min(t[i-1][j-1] , t[i-1][j])) + 1;
			}

			else
			{
				t[i][j] = 0;
			}
		}
	}

	int val = t[0][0];
	int maxi = 0;
	int maxj = 0;

	for(int i = 0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
		{
			if(t[i][j] > val)
			{
				val = t[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}

	for(int i = maxi; i > maxi - val;i--)
	{
		for(int j = maxj; j > maxj - val;j--)
		{
			cout << arr[i][j] << " ";
		}
		
		cout << endl;
	}

	cout << val << endl;
}

int main()
{
    int M[r][c] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
                     
    solve(M);
}