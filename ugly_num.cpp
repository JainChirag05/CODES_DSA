#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//nums with 2,3,5 as the only prime factors
//1 is an ugly num

int divide(int a , int b)
{
	while(a%b == 0)
	{
		a = a/b;
	}

	return a;
}

bool ugly (int n)
{
	n = divide(n , 2);
	n = divide(n , 3);
	n = divide(n , 5);

	if(n == 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int naive(int n)
{
	//complexity greater than nlogn and less than n^2

	int count = 1;
	int i = 2;

	while(count < n)
	{
		if(ugly(i))
		{
			count++;
		}

		i++;
	}

	return i-1;
}

int solve(int n)
{
	int ugly[n+1];

	int i2 = 0;
	int i3 = 0;
	int i5 = 0;

	int nm2 = 2;
	int nm3 = 3;
	int nm5 = 5;
	int nm = 1;
	ugly[0] = 1;

	for(int i = 1;i<n;i++)
	{
		nm = min(nm2 , min(nm3 , nm5));
		ugly[i] = nm;

		if(nm == nm2)
		{
			i2++;
			nm2 = ugly[i2] * 2;
		}

		if(nm == nm3)
		{
			i3++;
			nm3 = ugly[i3] * 3;
		}

		if(nm == nm5)
		{
			i5++;
			nm5 = ugly[i5] * 5;
		}
	}

	return ugly[n-1];
}


int main()
{
	int n;
	cin >> n;

	cout << naive(n) << endl;
	cout << solve(n) << endl;	
}