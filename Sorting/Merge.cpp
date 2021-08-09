#include <bits/stdc++.h>

//Time complexity of O(nlogn) and space complexity of O(n)

using namespace std;

void merge(int arr[] , int l , int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	
	int a[n1];
	int b[n2];
	
	for(int i = 0;i<n1;i++)
	{
		a[i] = arr[l+i];
	}
	
	for(int j = 0;j<n2;j++)
	{
		b[j] = arr[m+1+j];
	}
	
	int j = 0;
	int i = 0;
	int k = l;
	
	while(i < n1 && j < n2)
	{
		if(a[i] <= b[j])
		{
			arr[k] = a[i];
			i++;
		}
		
		else
		{
			arr[k] = b[j];
			j++;
		}
		
		k++;
	}
	
	while(i < n1)
	{
		arr[k] = a[i];
		i++;
		k++;
	}
	
	while(j < n2)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
}

void mergesort(int arr[] , int l , int r)
{
	if(l < r)
	{
		int m = l + (r-l)/2;
	
		mergesort(arr , l , m);
		mergesort(arr , m+1 , r);		
		merge(arr,l,m,r);
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
	
	mergesort(arr , l , r);
	
	for(int i = 0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}
	
