#include <bits/stdc++.h>

using namespace std;

char tree[10];

int root(char num)
{
	if(tree[0] == '\0')
	{
		tree[0] = num;
	}
	
	else
	{
		cout << "There is already a root";
	}
	
	return 0;
}

int left(char num , int p)
{
	if(tree[p] != '\0')
	{
		tree[2*p + 1] = num;
	}
	
	else
	{
		cout << "\nCan't set child at " << (p * 2) + 1<< " , no parent found";
	}
	
	return 0;
}

int right(char num , int p)
{
	if(tree[p] != '\0')
	{
		tree[2*p + 2] = num;
	}
	
	else
	{
		cout << "\nCan't set child at " << (p * 2) + 2<< " , no parent found";
	}
	
	return 0;
}


int printtree()
{
	cout << "\n";
	
	for(int i = 0;i<10;i++)
	{
		if(tree[i] == '\0')
		{
			cout << "-";
		}
		
		else
		{
			cout << tree[i];
		}
	}
	
	return 0;
}


int main()
{
	root('A');
    //left('B',0);
    right('C', 0);
    left('D', 1);
    right('E', 1);
    right('F', 2);
    printtree();
    return 0;
}
