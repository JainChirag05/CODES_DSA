#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void heapify(int arr[] , int n , int i) //here min heap is made. we need to make max heap
{
	int small = i;

	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] < arr[small])
	{
		small = l;
	}

	if(r < n && arr[r] < arr[small])
	{
		small = r;
	}

	if(small != i)
	{
		swap(arr[i] , arr[small]);
		heapify(arr , n , small);
	}
}

void sorting(int arr[] , int n)	//sorted in reverse order. If ascending order needed find largest
{
	for(int i = (n/2)-1;i>=0;i--)
	{
		heapify(arr , n , i);
	}

	for(int i = n-1;i>0;i--)
	{
		swap(arr[0] , arr[i]);

		heapify(arr , i , 0);
	}

	for(int i = n-1;i>=0;i--)
	{
		cout << arr[i] << " ";
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

	sorting(arr , n);
	
}