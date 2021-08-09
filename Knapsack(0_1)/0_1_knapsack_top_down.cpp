#include <bits/stdc++.h>
#define ll long long int

using namespace std;


//Base condition of recursive is initialisation of top-down

//Here for n== 0 and w==0 we set value in matrxi = 0 (just like base condition of recursion)

//n,w is replaced with (i,j) ;)

int solve(int wt[] , int val[] , int n , int w)
{
	int t[n+1][w+1];

	for(int i = 0;i<n+1;i++)
	{
		for(int j = 0;j<w+1;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<n+1;i++)
	{
		for(int j = 1;j<w+1;j++)
		{
			if(j >= wt[i-1])
			{
				int val1 = val[i-1] + t[i-1][j-wt[i-1]];
				int val2 = t[i-1][j];

				t[i][j] = max(val1 , val2);
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][w];
}

int main()
{
	int n;
	cin >> n;

	int w;
	cin >> w;

	int wt[n];
	int val[n];

	for(int i = 0;i<n;i++)
	{
		cin >> wt[i];
	}

	for(int i = 0;i<n;i++)
	{
		cin >> val[i];
	}

	cout << solve(wt , val , n , w) << endl;
	
}