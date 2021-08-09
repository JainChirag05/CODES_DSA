#include <bits/stdc++.h>

using namespace std;

void unsorted(int arr[] , int n)
{
	int s= 0;
	int e = n-1;
	int i = 0;
	int mini;
	int maxi;
	
	for(s = 0;s<n;s++)
	{
		if(arr[s] > arr[s+1])
		{
			break;
		}
		
		if(s== n-1)
		{
			cout << "Array already sorted" << endl;
			return;
		}
		
	}
	
	for(e = n-1;e>-0;e--)
	{
		if(arr[e-1] > arr[e])
		{
			break;
		}
		
	}
	
	mini = arr[s];
	maxi = arr[s];
	
	for(i = s;i<e;i++)
	{
		if(arr[i] < mini)
		{
			mini = arr[i];
		}
		
		if(arr[i] > maxi)
		{
			maxi = arr[i];
		}
	}
	
	for(i = 0;i<s;i++)
	{
		if(arr[i] > mini)
		{
			s = i;
			break;
		}
	}
	
	for(i = n-1;i>=e;i--)
	{
		if(arr[i] < maxi)
		{
			e = i;
			break;
		}
	}
	
	cout << s << " " << e <<  endl;
     
	return;
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
	
	unsorted(arr , n);
}
