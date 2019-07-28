#include<bits/stdc++.h>
using namespace std;
int freq[10][100];
int main(){
	string s;
	while(cin >> s){
		freq[s[0]-'0'][s[1]-'m']++;
	}
	int mini = INT_MAX;
	for(int i = 0 ; i < 10; i ++){
		for(int j = 0; j < 100; j++){
			mini = min(mini,max(3-freq[i][j],0));
			if(i<8) mini = min(mini,max(1-freq[i][j],0) + max(1-freq[i+1][j],0) + max(1-freq[i+2][j],0));
		}
	}
	cout << mini << endl;
	return 0;
}
