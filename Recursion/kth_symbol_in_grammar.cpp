#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int n , int k)
{
	if(k == 1 && n == 1)
	{
		return 0;
	}

	if(n == 0)
	{
		return 0;
	}

	int mid = pow(2 , n-1);

	if(k <= mid)
	{
		return solve(n - 1 , k);
	}

	else
	{
		return !solve(n-1 , k-mid);
	}
}

int main()
{
	int n,k;
	cin >> n >> k;

	cout << solve(n , k) << endl;
	
}