#include <iostream>
#include <vector>
#define ll long long int
#define max 100

using namespace std;

class stack
{
	int minn;
	int size;

public:
	stack()
	{
		minn = 99999;
		size = -1;
	}

	vector <pair<int,int>> arr;

	int getlast();
	int dellast();
	int add(int val);
	int mini();
};

int stack :: add(int x)
{
	if(size > max)
	{
		cout << "Full";
		return -1;
	}

	else
	{
		minn = min(x , minn);
	}

	arr.push_back({x , minn});
	size++;
}

int stack :: getlast()
{
	if(size == -1)
	{
		cout << "Empty";
		return -1;
	}

	return arr[size].first;
}

int stack :: dellast()
{
	if(size == -1)
	{
		cout << "Empty";
		return -1;
	}

	if(size > 0 && arr[size-1].second > arr[size].second)
	{
		minn = arr[size-1].second;
	}

	arr.pop_back();

	size--;

	return 1;
}

int stack :: mini()
{
	if(size == -1)
	{
		cout << "Empty";
		return -1;
	}

	return arr[size].second;
}

int main()
{
    stack s;
    int success = s.add(5);
    if (success == 1)
        cout << "5 inserted successfully\n";
 
    success = s.add(7);
    if (success == 1)
        cout << "7 inserted successfully\n";
 
    success = s.add(3);
    if (success == 1)
        cout << "3 inserted successfully\n";
    int min1 = s.mini();
    cout << "min element  :: " << min1 << endl;
 
    success = s.dellast();
    if (success == 1)
        cout << "removed successfully\n";
 
    success = s.add(2);
    if (success == 1)
        cout << "2 inserted successfully\n";
 
    success = s.add(9);
    if (success == 1)
        cout << "9 inserted successfully\n";
    int last = s.getlast();
    cout << "Last element :: " << last << endl;
 
    success = s.add(0);
    if (success == 1)
        cout << "0 inserted successfully\n";
    min1 = s.mini();
    cout << "min element  :: " << min1 << endl;
 
    success = s.dellast();
    if (success == 1)
        cout << "removed successfully\n";
 
    success = s.add(11);
    if (success == 1)
        cout << "11 inserted successfully\n";
    min1 = s.mini();
    cout << "min element  :: " << min1 << endl;
 
    return 0;
}