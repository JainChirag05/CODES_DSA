#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t[1001][1001];

int solve(int arr[] , int i , int j)
{
	int ans = INT_MAX;

	int left;
	int right;
	int temp;

	if(i >= j)
	{
		t[i][j] = 0;
		return 0;
	}

	for(int k = i;k<j;k++)
	{
		if(t[i][k] != -1)
    	{
    		left = t[i][k];
    	}

    	else
    	{
    		left = solve(arr , i , k);
    	}

    	if(t[k+1][j] != -1)
    	{
    		right = t[k+1][j];
    	}

    	else
    	{
    		right = solve(arr , k+1 , j);
    	}

        temp = left + right + (arr[i-1]*arr[k]*arr[j]);
           
        ans = min(ans , temp);
	}

	return t[i][j] = ans;
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

	memset(t , -1 , sizeof(t));

	cout <<solve(arr , 1 , n-1);
	
}