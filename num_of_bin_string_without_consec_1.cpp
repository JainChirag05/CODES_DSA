#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve1(int n)
{
	int a[n]; //string ending in 0
	int b[n]; //string ending in 1

	a[0] = b[0] = 1;

	for(int i = 1;i<n;i++)
	{
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1]; 
	}

	return a[n-1] + b[n-1];
}


//(n+2)th fib num

int main()
{
	int n;
	cin >> n;

	cout << solve1(n) << endl;
	cout << solve2(n) << endl;
	
}