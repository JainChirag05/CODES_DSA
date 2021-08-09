#include <bits/stdc++.h>

using namespace std;

int partition(int arr[] , int l , int r)
{
	int pivot = arr[l];

	int i = l;
	int j = r;

	while(i < j)
	{
		while(arr[i] <= pivot)
		{
			i++;
		}

		while(arr[j] > pivot)
		{
			j--;
		}

		if(i < j)
		{
			swap(arr[i] , arr[j]);
		}
	}

	swap(arr[l] , arr[j]);

	return j;
}

void quicksort(int arr[] , int l , int r)
{
	if(l < r)
	{
		int pi = partition(arr , l , r);
	
		quicksort(arr , l , pi-1);
		quicksort(arr , pi+1 , r);
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
	
	int l = 0;
	int r = n-1;
	
	quicksort(arr , l , r);
	
	for(int i = 0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}

