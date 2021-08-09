#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int n)
{
	int fib[n+2];

	fib[0] = 0;
	fib[1] = 1;

	for(int i = 2;i<=n;i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}

	for(int i = 0;i<=n;i++)
	{
		cout << fib[i] << " ";
	}

	cout << endl;
	
}

void fib_space(int n)
{
	int a = 0;
	int b = 1;
	int c , i;

	cout << 0 << " ";
	cout << 1 << " ";

	for(i = 2;i<=n;i++)
	{
		c = a + b;
		a = b;
		b = c;

		cout << b << " ";
	}

	//return b;
}

int main()
{
	int n;
	cin >> n;

	solve(n);
	fib_space(n);
	
}