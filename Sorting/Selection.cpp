#include <bits/stdc++.h>


// This has a time complexity of O(n^2) and space complexity of O(1)

using namespace std;

void selectionsort(int arr[] , int n)
{
	int min = 0;
	
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
			
		swap(arr[i] , arr[min]);
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
	
	selectionsort(arr , n);
	
	for(int i = 0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}
	
