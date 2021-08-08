#include <bits/stdc++.h>
#define ll long long int

using namespace std;


void m1(int a[] , int n , int b[] , int m)
{
	int sum1 = 0;
	int sum2 = 0;

	for(int i = 0;i<n;i++)
	{
		sum1 += a[i];
	}

	for(int i = 0;i<m;i++)
	{
		sum2 += b[i];
	}

	int diff = abs(sum1 - sum2);
	int flag = 0;

	int i = 0 , j = 0;

	while(i < n && j < m)
	{
		if(a[i] + b[j] == diff)
		{
			flag = 1;
			cout << a[i] << " " << b[j];
			break;
		}

		else if(a[i] > b[j])
		{
			i++;
		}

		else
		{
			j++;
		}
	}

	if(flag == 0)
	{
		cout << "None";
	}
}

void m2(int a[] , int n , int b[], int m)
{
	unordered_map<int,int> mp;

	int sum1 = 0;
	int sum2 = 0;

	for(int i = 0;i<n;i++)
	{
		sum1 += a[i];
	}

	for(int i = 0;i<m;i++)
	{
		sum2 += b[i];
	}

	int diff = sum1 - sum2;
	int flag = 0;

	if(diff%2 == 1)
	{
		cout << "None";
	}

	for(int i = 0;i<n;i++)
	{
		mp[a[i]]++;
	}

	for(int i = 0;i<n;i++)
	{
		if(mp.find(b[i] + diff/2) != mp.end())
		{
			flag = 1;
			cout << b[i] << " " << b[i] + diff/2 << endl;
			break;
		}
	}

	if(flag == 0)
	{
		cout << "None";
	}
}



int main()
{
	int n;
	cin >> n;

	int a[n];

	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}

	int m;
	cin >> m;

	int b[m];

	for(int i = 0;i<m;i++)
	{
		cin >> b[i];
	}

	m1(a,n,b,m);
	cout << endl;
	m2(a,n,b,m);
	
}