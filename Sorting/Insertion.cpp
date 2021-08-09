#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void insertion(int arr[] , int n)
{
	for(int i = 1;i<n;i++)
	{
		int curr = arr[i];

		int ind = i-1;

		while(arr[ind] > curr && ind>=0)
		{
			arr[ind+1] = arr[ind];
			ind--; 
		}

		arr[ind + 1] = curr;	
	}

	for(int i = 0;i<n;i++)
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

	insertion(arr , n);
}