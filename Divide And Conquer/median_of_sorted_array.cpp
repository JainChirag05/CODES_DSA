#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int naive(int a[] , int b[] , int n)
{
	int m1 = -1 , m2 = -1;
	int i = 0 , j = 0;

	for(int count = 0;count <= n ; count++)
	{
		if(i == n) //all ele of a are lesser than b
		{
			m1 = m2;
			m2 = b[0];
			break;
		}

		else if(j == n) //all ele of b are lesser than a
		{
			m1 = m2;
			m2 = a[0];
			break;
		}

		if(a[i] <= b[j])
		{
			m1 = m2;
			m2 = a[i];
			i++;
		}

		else
		{
			m1 = m2;
			m2 = b[j];
			j++;
		}
	}

	return m1 + (m2 - m1)/2;
}

int median(int arr[] ,  int n)
{
	if(n%2 == 0)
	{
		return (arr[n/2] + arr[n/2 - 1])/2;
	}

	else
	{
		return arr[n/2];
	}
}

int better(int a[] , int b[] , int n)
{
	if(n == 0)
	{
		return -1;
	}

	if(n == 1)
	{
		return (a[0] + b[0])/2;
	}

	if(n == 2)
	{
		return (max(a[0] , b[0]) + min(a[1] , b[1]))/2;
	}

	int m1 = median(a , n);
	int m2 = median(b , n);

	if(m2 > m1)
	{
		if(n%2 == 0)
		{
			return better(a + n/2 - 1 , b , n - n/2 + 1);
		}

		else
		{
			return better(a + n/2 , b , n * n/2);
		}
	}

	if(n%2 == 0)
	{
		return better(b + n/2 - 1 , a , n - n/2 + 1);
	}

	else
	{
		return better(b + n/2 , a , n - n/2);
	}
}

int main()
{
	int n;
	cin >> n;

	int a[n];
	int b[n];

	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}

	for(int i = 0;i<n;i++)
	{
		cin >> b[i];
	}

	cout << naive(a,b,n) <<endl;
	
}