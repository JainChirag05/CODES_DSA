#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int maxi(int arr[] , int ind , int n)
{
	if(ind >=n-2) //only 2 ele left
	{
		if(arr[ind] < arr[ind+1])
		{
			return arr[ind+1];
		}

		else
		{
			return arr[ind];
		}
	}

	int ans = maxi(arr , ind + 1 , n);

	if(arr[ind] > ans)
	{
		return arr[ind];
	}

	else
	{
		return ans;
	}
}

int mini(int arr[] , int ind , int n)
{
	if(ind >=n-2) //only 2 ele left
	{
		if(arr[ind] > arr[ind+1])
		{
			return arr[ind+1];
		}

		else
		{
			return arr[ind];
		}
	}

	int ans = mini(arr , ind + 1 , n);

	if(arr[ind] < ans)
	{
		return arr[ind];
	}

	else
	{
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
	
	cout << mini(arr , 0 , n) << endl;
	cout << maxi(arr , 0 , n) << endl;
}