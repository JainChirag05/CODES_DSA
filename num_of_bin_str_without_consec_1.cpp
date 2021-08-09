#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int n)
{
	int a[n] , b[n];
	a[0] = 1;
	b[0] = 1;

	for(int i = 1;i<n;i++)
	{
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}

	cout << a[n-1] + b[n-1];
}

int main()
{
	int n;
	cin >> n;

	solve(n);	
}