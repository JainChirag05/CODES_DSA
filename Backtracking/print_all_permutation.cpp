#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void permute(string a , int l , int r , set<string> &s)
{
	if(l == r)
	{
		s.insert(a);
		return;
	}

	for(int i = l;i<=r;i++)
	{
		swap(a[l] , a[i]);
		permute(a,l+1,r,s);
		swap(a[l] , a[i]);
	}
}

int main()
{
	string a;
	cin >> a;

	set<string> s;

	vector<string> ans;

	permute(a,0,a.length()-1,s);

	for(auto i : s)
	{
		ans.push_back(i);
	}

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}

	
}