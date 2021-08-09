#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool replace(string a , string b)
{
	int n = a.length();
	int i = 0;
	bool diff = false;

	while(i < n)
	{
		if(a[i] != b[i])
		{
			if(diff)
			{
				return false;
			}

			diff = true;
		}

		i++;
	}

	return true;
}

bool insert(string a , string b)
{
	int n = a.length();
	int m = b.length();
	int ind1 = 0;
	int ind2 = 0;

	while(ind1 < n && ind2 < m)
	{
		if(a[ind1] != b[ind2])
		{
			if(ind1 != ind2)
			{
				return false;
			}

			ind2++;
		}

		else
		{
			ind1++;
			ind2++;
		}
	}

	return true;
}

bool check(string a , string b)
{
	int n = a.length();
	int m = b.length();

	if(n == m)
	{
		return replace(a , b);
	}

	else if(n + 1 == m)
	{
		return insert(a , b);
	}

	else if(m + 1 == n)
	{
		return insert(b,a);
	}

	return false;
}

int main()
{
	string a;
	cin >> a;
	string b;
	cin >> b;

	cout << check(a ,b);
	
}