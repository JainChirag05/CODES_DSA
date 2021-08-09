#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	if(n == 0)
	{
		cout << 0;
	}

	else if(n == 1)
	{
		cout << arr[0];
	}

	else
	{
		int max_end = arr[0];
		int min_end = arr[0];
		int ans = arr[0];

		for(int i = 1;i<n;i++)
		{
			if(arr[i] == 0)
			{
				max_end = 1;
				min_end = 1;
			}
			
			int temp = max_end;
			max_end = max({arr[i] , arr[i]*max_end , arr[i]*min_end});
			min_end = min({arr[i] , arr[i]*temp , arr[i]*min_end});
			ans = max(ans , max_end);
		}
		cout << ans;
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

	solve(arr , n);
	
}