#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, num[100000],count = 0;
	set<int> sol;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> num[i];
		sol.insert(num[i]);
		for(int j = i-1 ; j >= 0 ; j--){
			if(num[j] == (num[j] | num[i]))break;
			num[j] |= num[i];
			sol.insert(num[j]);
		}
	}
	cout << sol.size() << endl;
	return 0;
}
