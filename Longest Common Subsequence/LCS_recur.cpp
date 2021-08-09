#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int lcs(string a , string b , int x , int y)
{
	if(x == 0 || y == 0)
	{
		return 0;
	}

	if(a[x-1] == b[y-1])
	{
		return 1+lcs(a,b,x-1,y-1);
	}

	else
	{
		return max(lcs(a,b,x-1,y) , lcs(a,b,x,y-1));
	}
}

int main()
{
	string a;
	cin >> a;
	
	string b;
	cin >> b;

	int x = a.length();
	int y = b.length();

	cout << lcs(a,b,x,y);
}