#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int naive(int x , int y) //O(n)
{
	if(y == 0)
	{
		return 1;
	}

	else if(y%2 == 0)
	{
		return naive(x , y/2) * naive(x , y/2);
	}

	else
	{
		return naive(x , y/2) * x * naive(x , y/2);
	}
}

float better(int x , int y)
{
	float temp;

	if(y == 0)
	{
		return 1;
	}

	temp = better(x , y/2);

	if(y%2 == 0)
	{
		return temp * temp;
	}

	else
	{
		if(y > 0)
		{
			return temp * temp * x;
		}

		else
		{
			return (float)(temp*temp) * (1.0/x);
		}
	}
}

int main()
{
	int x,y;
	cin >> x >> y;

	cout << naive(x,y) << endl;

	cin >> x;
	cin >> y;

	cout << better(x,y) << endl;
	
}