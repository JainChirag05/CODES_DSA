#include <bits/stdc++.h>

using namespace std;

int crossover(int arr[] , int low , int high , int x)
{
	int mid = (high+low)/2;
	
	if(low > arr[x])
	{
		return low;
	}
	
	if(arr[high] <= x)
	{
		return high;
	}
	
	if(arr[mid] <=x && arr[mid+1] > x)
	{
		return mid;
	}
	
	if(arr[mid] < x)
	{
		return crossover(arr, mid+1 , high ,x);
	}
	
	return crossover(arr , low , mid-1,x);
}

void closest(int arr[] , int x , int k, int n)
{
	int l = crossover(arr , 0 , n-1 , x);
	int r = l+1;
	int count = 0;
	
	if(arr[l] == x)
	{
		l--;
	}
	
	while(l>=0 && r < n && count < k)
	{
		if(x - arr[l] < arr[r] - x)
		{
			cout << arr[l] << " ";
			l--;
		}
		else
		{
			cout << arr[r] << " ";
			r++;
		}
		count++;
	}
	
	while(count < k && l >= 0)
	{
		cout << arr[l] << " ";
		count++;
		l--;
	}
	
	while(count < k && r < n)
	{
		cout << arr[r] << " ";
		count++;
		r++;
	}
}

int main()
{
	int n,k,x;
	cin >> n >> k >> x;
	
	int arr[n];
	
	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}
	
	closest(arr , x , k ,n);
}	
	
