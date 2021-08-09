#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n1;
	cin >> n1;
	
	int arr1[n1];
	
	for(int i = 0;i<n1;i++)
	{
		cin >> arr1[i];
	}
	
	int n2;
	cin >> n2;
	
	int arr2[n2];
	
	for(int i = 0;i<n2;i++)
	{
		cin >> arr2[i];
	}
	
	int k;
	cin >> k;
	
	int l = 0;
	int r = n2 - 1;
	
	int diff = INT_MAX;
	int ansl = 0;
	int ansr = 0;
	
	while(l < n1 && r >=0)
	{
		if(abs(arr1[l] + arr2[r] - k) < diff)
		{
			ansl = l;
			ansr = r;
			diff = abs(arr1[l] + arr2[r] - k);
		}
		
		if(arr1[l] + arr2[r] > k)
		{
			r--;
		}
		
		else
		{
			l++;
		}
	}
	
	cout << diff << endl;
	cout << '[' << arr1[ansl] << ',' << arr2[ansr] << ']' << endl;
}
