#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve_lcs(int a[] , int b[] ,int x , int y)
{
	int t[x+1][y+1];

	for(int i =0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=x;i++)
	{
		for(int j = 1;j<=y;j++)
		{
			if(a[i-1] == b[j-1])
			{
				t[i][j] = 1 + t[i-1][j-1];
			}

			else
			{
				t[i][j] = max(t[i-1][j] , t[i][j-1]);
			}
		}
	}

	return t[x][y];
}

int lis(int a[] , int n)
{
	int dp[n] = {1};

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				dp[i] = max(dp[i] , 1 + dp[j]);
			}
		}
	}

	int ans = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		ans = max(ans , dp[i]);
	}

	return ans;
}

void print_lis(int a[] , int b[] , int x , int y)
{
	int t[x+1][y+1];

	for(int i = 0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=x;i++)
	{
		for(int j = 1;j<=y;j++)
		{
			if(a[i-1] == b[j-1])
			{
				t[i][j] = 1 + t[i-1][j-1];
			}

			else
			{
				t[i][j] = max(t[i-1][j] , t[i][j-1]);
			}
		}
	}

	int i = x;
	int j = y;
	vector <int> ans;

	while(i > 0 && j > 0)
	{
		if(a[i-1] == b[j-1])
		{
			ans.push_back(a[i-1]);
			i--;
			j--;
		}

		else
		{
			if(t[i-1][j] > t[i][j-1])
			{
				i--;
			}

			else
			{
				j--;
			}
		}
	}

	reverse(ans.begin() , ans.end());

	int sum = 0;

	for(int k = 0;k<ans.size();k++)
	{
		cout << ans[k] << " ";
	}

	cout << endl;

	for(int i = 0;i<ans.size();i++)
	{
		sum += ans[i];
	}

	cout << sum << endl;
}

int best(int arr[] , int n)
{
	vector<int> ans;

	ans.push_back(arr[0]);

	for(int i = 1;i<n;i++)
	{
		if(ans.back() < arr[i])
		{
			ans.push_back(arr[i]);
		}

		else
		{
			auto it = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
			ans[it] = arr[i];
		}
	}

	return ans.size();
}


int main()
{
	int n;
	cin >> n;

	int a[n];
	int b[n];

	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b , b +n);

	cout << solve_lcs(a,b,n,n) << endl;
	cout << lis(a , n) << endl;

	print_lis(a,b,n,n);
}