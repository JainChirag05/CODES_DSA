#include <bits/stdc++.h>

// This has a worst case time complexity of O(n^2) and best case of O(n)

using namespace std;

void bubble(int arr[] , int n)
{
	for(int i = 0;i<n;i++)
	{
		int flag = 0;
		
		for(int j = 0;j<n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j] , arr[j+1]);
				flag = 1;
			}
		}
		
		if(flag == 0)
		{
			break;
		}
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
	
	bubble(arr , n);
	
	for(int i = 0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
}
