#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int main() {
	int T,num[N] = {},dv[N] = {};
	bool term[N] = {};
	vector<pair<int,int>> rangos;
	cin >> T;

	for(int i = 0 ; i < T ; i ++){
		int a,b;
		cin >> a >> b;
		rangos.push_back(make_pair(a,b));
	}

	for(int i = 1 ; i < N ; i++){
		for(int j = i ; j < N ; j+=i){
			dv[j]++;
		}
	}

	num[1]++; int aux = 1,contaux = 1; term[1] = true;
	for(int i = 2; i < N ; i++){
		if(i == aux + dv[aux]){

			aux = aux + dv[aux];
			term[aux] = true;
			num[aux] += ++contaux;
		}else{
			num[i] +=contaux;
		}
	}

	for(int i = 0 ; i < T ; i ++){

		if(term[rangos[i].first]){
			cout << "Case "<<i+1<<": "<< num[rangos[i].second] - num[rangos[i].first] + 1 << endl;
		}else{
			cout << "Case "<<i+1<<": "<< num[rangos[i].second] - num[rangos[i].first] << endl;
		}
	}
	
	return 0;
}
