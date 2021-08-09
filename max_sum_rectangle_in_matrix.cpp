#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int kadane(vector<int> ans)
{
	int n = ans.size();
	int max_far = INT_MIN;
	int max_end = 0;

	for(int i = 0;i<n;i++)
	{
		max_end = max(ans[i] , ans[i] + max_end);
		max_far = max(max_end , max_far);
	}

	return max_far;
}

void solve(vector<vector<int>> arr , int r , int c)
{
	int res = INT_MIN;

	for(int i = 0;i<r;i++)
	{
		vector<int> ans(c);

		for(int j = i;j<r;j++)
		{
			for(int k = 0;k<c;k++)
			{
				ans[k] += arr[j][k];
			}

			res = max(res , kadane(ans));
		}
	}

	cout << res << endl;
}

int main()
{
	int r,c;
	cin >> r >> c;

	vector<vector<int>> arr(r , vector<int> (c));

	for(int i = 0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
		{
			cin >> arr[i][j];
		}
	}

	solve(arr , r , c);
	
}