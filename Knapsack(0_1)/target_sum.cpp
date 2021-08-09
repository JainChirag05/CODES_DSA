#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//Assign +- before element such that total is given to equal num

//Similar to diff problem

//num_of_subset_with_given_diff

int check(int arr[] , int n , int sum)
{
	int t[n+1][sum+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=sum;j++)
		{
			if(i == 0)
			{
				t[i][j] = 0;
			}

			if(j == 0)
			{
				t[i][j] = 1;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=sum;j++)
		{
			if(j >= arr[i-1])
			{
				t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][sum];
}

int final(int arr[] , int n , int target)
{
	int sum = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];
	}

	if((target + sum)%2 == 1)
	{
		return 0;
	}

	else
	{
		int ans = check(arr , n , (target+sum)/2);

		return ans;
	}	
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

	int diff;
	cin >> diff;

	cout << final(arr , n , diff);
	
	
}