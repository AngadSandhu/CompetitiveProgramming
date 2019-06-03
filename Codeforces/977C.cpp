#include <bits/stdc++.h>
using namespace std;

int main()
{
	long int n, k, r;
	cin >> n >> k;
	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	sort(array, array+n);
	
	if (k == 0)
	{
		if (array[0] == 1)
		{
			r = -1;
		}
		else
		{
			r = 1;
		}
	}
	
	else if (n == k)
	{
		r = array[k-1];
	}
	
	else if (array[k-1] != array[k])
	{
		r = array[k-1];
	}
	else
	{
		r = -1;
	}

	cout << r;
	 
	return 0;
}
