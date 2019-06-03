#include <bits/stdc++.h>
using namespace std;
#define N 100

int main()
{
	int n;
	int max = 0;
	char twogram[2];
	char maxtwogram[2];
	cin >> n;
	char *string = new char [N];
	cin >> string;
	
	for(int i = 0; i < n-1; i++)
	{
		twogram[0] = string[i];
		twogram[1] = string[i+1];
		for(int j = 0, count = 0; j < n-1; j++)
		{
			if ((string[j] == twogram[0]) && (string[j+1] == twogram[1]))
			{
				count++;
			}
			if (count > max)
			{
				max = count;
				maxtwogram[0] = twogram[0];
				maxtwogram[1] = twogram[1];
			}
		}

	}
	
	for (int i = 0; i < 2; i++)
	{
		cout << maxtwogram[i];
	}
	
	return 0;
}
