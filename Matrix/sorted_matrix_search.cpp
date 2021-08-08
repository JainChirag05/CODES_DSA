#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	int target;
	cin >> target;

	int arr[n][m];

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin >> arr[i][j];
		}
	}

	int r = 0 , c = m-1;
	while(r < n && c >= 0)
	{
		if(arr[r][c] == target)
		{
			cout << "true" << endl;
			break;
		}

		else if(target > arr[r][c])
		{
			r++;
		}

		else
		{
			c--;
		}
	}	

}