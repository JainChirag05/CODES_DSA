#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector <int> check(int arr[] , int n , int sum)
{
	bool t[n+1][sum+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=sum;j++)
		{
			if(i == 0)
			{
				t[i][j] = false;
			}
			
			if(j == 0)
			{
				t[i][j] = true;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=sum;j++)
		{
			if(j >= arr[i-1])
			{
				t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	vector<int> ans;

	for(int i = 0;i<=sum/2;i++)
	{
		if(t[n][i] == true)
		{
			ans.push_back(i);
		}
	}

	return ans;
}

int final(int arr[] , int n)
{
	int sum = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];
	}

	vector<int> v = check(arr , n , sum);
	int mini = INT_MAX;

	for(int i = 0;i<v.size();i++)
	{
		mini = min(mini , (sum - 2 * v[i]));
	}

	return mini;
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	cout << final(arr , n);
	
}
	
