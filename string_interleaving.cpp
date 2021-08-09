#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool check(string s1, string s2 , string s3 , int l1 ,int l2,int l3,int p1,int p2,int p3)
{
	unordered_map<string,bool> mp;

	if(l3 == p3)
	{
		if(p1 == l1 & p2 == l2)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);

	if(p2 == l2)
	{
		if(s1[p1] == s3[p3])
		{
			return mp[key] = check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
		}

		else
		{
			return mp[key] = false;
		}
	}

	if(p1 == l1)
	{
		if(s2[p2] == s3[p3])
		{
			return mp[key] = check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
		}

		else
		{
			return mp[key] = false;
		}
	}

	bool one = false;
	bool two = false;

	if(s1[p1] == s3[p3])
	{
		one = check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
	}

	if(s2[p2] == s3[p3])
	{
		two = check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
	}

	return mp[key] = one || two;
}

int main()
{
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;

		int l1 = s1.length();
		int l2 = s2.length();
		int l3 = s3.length();

	cout << check(s1,s2,s3,l1,l2,l3,0,0,0);
	
}