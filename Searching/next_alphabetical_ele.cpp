#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(char arr[] , int n , char val)
{
	int res = -1;
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int m = l + (h-l)/2;

		if(arr[m] == val)
		{
			l = m + 1;
		}

		else if(arr[m] < val)
		{
			l = m + 1;
		}

		else
		{
			res = m;
			h = m-1;
		}
	}

	return res;
}

int main()
{
	int n;
	cin >> n;

	char arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	char val;
	cin >> val;

	int ind = solve(arr , n ,val);

	if(ind != -1)
	{
		cout << arr[ind] << endl;
	}

	else 
	{
		cout << "None";
	}
	
}