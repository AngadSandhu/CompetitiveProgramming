#include <bits/stdc++.h>
using namespace std;

int main() {
	int n[2];
	vector<pair<int,int>> p[2];
	cin >> n[0] >> n[1];
	for(int i = 0,a,b ; i < n[0] ; i++){
		cin >> a >> b;
		p[0].push_back(make_pair(a,b));
	}
	for(int i = 0,a,b ; i < n[1] ; i++){
		cin >> a >> b;
		p[1].push_back(make_pair(a,b));
	}
	int ar[] = {0,1};
	set<int>resp;
	int res = -1;
	do{
		for(int i = 0; i < n[ar[0]] ; i++){
			res = -1;
			for(int j = 0 ; j < n[ar[1]] ; j++){
			
			int a,b,c,d;
		    a = p[ar[0]][i].first ,b = p[ar[0]][i].second,c = p[ar[1]][j].first, d = p[ar[1]][j].second;
			if((a==c && b!=d) || (a==d && c!=b)){
					if(res == -1) res = a; 
					else if(a != res){
						cout <<"-1" << endl;
						return 0;
					} 
				}
			if((b==d && a!=c) || ((b==c) && (a!=d))){
					if(res == -1) res = b;
					else if(b != res) {
						cout <<"-1" << endl;
						return 0;
					}
				}
			}
			
			if(res != -1) resp.insert(res);
		}
		
	}while(next_permutation(ar,ar+2));
	if(resp.size() == 1){
		cout << *resp.begin() << endl;
	}else if(resp.size() >= 2){
		cout << 0 << endl;
	}
	return 0;
}
