#include<iostream>
#include<vector>
using namespace std;
#define N 1000
#define P 100000
int main(){
	int n, m, q;
	cin >> n >> m >> q;
	char *s = new char[N];
	char *t = new char[N];
	cin >> s >> t;
	int rangos[P][2];
	vector <int> sol;
	int count[P] = {};
	for(int i =0 ; i < q; i++){
		cin >> rangos[i][0]>> rangos[i][1];
	}
	
	bool coincidencia = true;
	for(int i =0 ; i < n ; i++){
		coincidencia = true;
		for(int j = 0; j < m; j++){
			if(s[i+j]!=t[j]){
				coincidencia = false;
				break;
				}
		}
		if(coincidencia){
			sol.push_back(i);
		}
	}
	
	for(int i = 0; i< q; i++){
		for(int j =0; j < sol.size(); j++){
			if(sol[j] >= rangos[i][0]-1 && sol[j] <= rangos[i][1]-1 && sol[j] <= rangos[i][1]-m){
				count[i]++;
			}
			
		}
	}
	for(int i =0; i<q; i++){
		cout << count[i] << endl;
	}
	return 0;
}

