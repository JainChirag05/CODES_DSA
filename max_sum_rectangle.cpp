#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int kadane(vector<int> arr , int n)
{
	int max_far = INT_MIN;
	int max_end = 0;

	for(int i = 1;i<n;i++)
	{
		max_end += arr[i];

		if(max_end > max_far)
		{
			max_far = max_end;
		}

		if(max_end < 0)
		{
			max_end = 0;
		}
	}

	return max_far;
}

int main()
{
	int r , c;
	cin >> r >> c;

	int mat[r][c];

	for(int i = 0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
		{
			cin >> mat[i][j];
		}
	}

	int res = INT_MIN;

	for(int i = 0;i<r;i++)
	{
		vector <int> ans(c);
		for(int j = i;j<r;j++)
		{
			for(int col = 0;col<c;col++)
			{
				ans[col] += mat[j][col];
			}

			res = max(res , kadane(ans , c));
		}
	}

	cout << res << endl;
	
}