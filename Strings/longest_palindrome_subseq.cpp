#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string calnoob(string s)
{
	int n = s.length();
	int st = 0,end = 0,max_len = 1;
	int r;
	int l;

	for(int i = 0;i<n-1;i++)
	{
		if(n%2 == 0)
		{
			r = i;
			l = i;
		}

		else
		{
			l = i;
			r = i+1;
		}

		while(l >=0 && r < n)
		{
			if(s[l] == s[r])
			{
				l--;
				r++;
			}
			else
			{
				break;
			}
		}

		int len = r-l-1;

		if(len > max_len)
		{
			max_len = len;
			st = l + 1;
			end = r - 1;

		}
	}

	return s.substr(st , max_len);
}

void noob(string s)
{
	int n = s.length();

	if(n == 0)
	{
		cout << "empty";
	}

	if(n == 1)
	{
		cout << s;
	}

	else
	{
		cout << calnoob(s);
	}

}

int main()
{
	string s;
	cin >> s;

	noob(s);
	
}