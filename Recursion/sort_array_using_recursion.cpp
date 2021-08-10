#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void inserting(vector <int> &v , int temp)
{
	if(v.size() == 0 || v[v.size() - 1] <= temp)
	{
		v.push_back(temp);
		return;
	}

	int val = v[v.size() - 1];
	v.pop_back();

	inserting(v , temp);

	v.push_back(val);
}


void sorting(vector <int> &v)
{
	if(v.size() == 1)
	{
		return;
	}

	int temp = v[v.size() - 1];
	v.pop_back();

	sorting(v);

	inserting(v , temp);
}


int main()
{
	int n;
	cin >> n;

	vector <int> v;


	for(int i = 0;i<n;i++)
	{
		int t;
		cin >> t;

		v.push_back(t);
	}

	sorting(v);

	for(int i = 0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	
}