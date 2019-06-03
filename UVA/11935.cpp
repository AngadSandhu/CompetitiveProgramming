#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;
int goal;
vector<int> events[100000];

bool posiblecapacity(double capacity){
	double tank = capacity;
	double gasto = events[0][0];
	int leak = 0;
	for(int i = 0 ; i < goal ; i++){
		for(int j = 0 ; j < events[i].size() ; j++){
			if(events[i][j] > 0) gasto = events[i][j];
			if(events[i][j] == -1) leak++;
			if(events[i][j] == -2) tank = capacity;
			if(events[i][j] == -3) leak = 0;
		}
			tank -= gasto/100;
			tank -= leak;
			if(tank < 0 ) return false;
	}
	return tank >= 0;
}

int main() {
	string s;
	while(true){
		for(int i = 0 ; i < 100002 ; i++){
			events[i].clear();
		}
		getline(cin,s);
		if(s == "0 Fuel consumption 0") break;
		else{
			events[0].pb(stoi(s.substr(18,s.size()-18)));
			while(true){
				int aux;
				cin >> aux;
				getline(cin,s);
				if(s == " Goal"){
					goal = aux;
					double l = 0, r = 100000,med;
					for(int i = 0 ; i < 32 ; i++){
						med = (r+l)/2;
						if(posiblecapacity(med)) r = med;
						else l = med;
					}
					printf("%.3f\n",med);
					break;
				}
				if(s.substr(1,16) == "Fuel consumption"){
					events[aux].pb(stoi(s.substr(18,s.size()-18)));
				}
				if(s == " Leak"){
					events[aux].pb(-1);
				}
				if(s == " Gas station"){
					events[aux].pb(-2);
				}
				if(s == " Mechanic"){
					events[aux].pb(-3);
				}
				
			}
		}
	}
}
