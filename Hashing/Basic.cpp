#include <bits/stdc++.h>
#define ll long long int
#define max 1000

using namespace std;

bool has[max+1][2] = {0,0};

bool check(int x)
{
	if(x >=0)
	{
		if(has[x][0] != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if(x < 0)
	{
		if(has[abs(x)][1] != 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}

void add(int arr[] , int n)
{
	for(int i = 0;i<n;i++)
	{
		if(arr[i] >= 0)
		{
			has[arr[i]][0] = 1;
		}

		else
		{
			has[abs(arr[i])][1] = 1;
		}
	}
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

	add(arr , n);

	int target;
	cin >> target;

	if(check(target))
	{
		cout << "yep" << endl;
	}

	else
	{
		cout << "nope" << endl;
	}
}