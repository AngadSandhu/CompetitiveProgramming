#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,minC,maxC,dif,prob[15],count = 0;
	cin >> n >> minC >> maxC >> dif;
	for(int i = 0 ; i < n; i++){
		cin >> prob[i];
	}
	
	int com = 0,aux=0;
	vector<int>sol;
	for(int i = 0; i < (1<<n) ; i++){
		com = 0; aux =0; sol.clear();
		for(int j = 0 ; j < n; j++){
			if((i>>j)&1){
				com += prob[j];
				aux++;
				sol.push_back(prob[j]);
			}
		}
		sort(sol.begin(),sol.end());
		if((com >= minC) && (com <= maxC) && (abs(sol.front() - sol.back()) >= dif) && aux >=2){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
