#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,obe[1000][2],clue[1000][2];
        long long int sol[2] = {};
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> obe[i][0] >> obe[i][1];
	}
	for(int i = 0 ; i < n ; i++){
		cin >> clue[i][0] >> clue[i][1];
	}
	for(int i = 0 ; i < n ; i++){
		sol[0] +=obe[i][0] + clue[i][0];
		sol[1] += obe[i][1] + clue[i][1];
	}
	cout << sol[0]/n << " " <<  sol[1]/n;
	return 0;
}
