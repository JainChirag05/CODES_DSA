#include <bits/stdc++.h>
#define ll long long int

using namespace std;


//matrix of diff sizes are given. Multiply by using minimum multiplications

//for eg A(2x3) multiplied with B(3x6) will have 2x3x6 = 36 multiplications or has a cost 36

//find min cost by using appropropriate brackets

int solve(int arr[] , int i , int j)
{
	int ans = INT_MAX;

	if(i >= j)
	{
		return 0;
	}

	for(int k = i;k<j;k++)
	{
		int temp = solve(arr , i , k) + solve(arr , k+1 , j) + (arr[i-1]*arr[k]*arr[j]);

		ans = min(temp , ans);
	}

	return ans;
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

	cout <<solve(arr , 1 , n-1);
	
}