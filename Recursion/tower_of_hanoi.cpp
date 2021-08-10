#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int n , char from , char to , char aux)
{
	if(n <= 1)
	{
		cout << "Move Disc 1 from" << " " << from << " " << "to" << " " << to << endl;
		return;
	}

	solve(n-1 , from , aux , to);
	cout << "Move Disc" << " " <<  n  << " " << "from" << " " << from << " " << "to" << " " << to << endl;
	solve(n-1 , aux , to , from);
}


int main()
{
	int n;
	cin >> n;

	solve(n , 'A' , 'C' , 'B');
}