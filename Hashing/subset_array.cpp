#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr1[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr1[i];
	}

	int m;
	cin >> m;

	int arr2[m];

	int flag = 0;

	for(int i = 0;i<m;i++)
	{
		cin >> arr2[i];
	}

	set <int> hash;

	for(int i =0;i<n;i++)
	{
		hash.insert(arr1[i]);
	}

	for(int i = 0;i<m;i++)
	{
		if(hash.find(arr2[i]) == hash.end())
		{
			flag = 1;
			break;
		}
	}	

	if(flag == 1)
	{
		cout << "nope" << endl;
	}

	else
	{
		cout << "yep" << endl;
	}
}