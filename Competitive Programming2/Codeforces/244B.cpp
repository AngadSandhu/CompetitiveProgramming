#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,count = 0, num = 0;
	vector<int> sol;
	cin >> n;
	sol.clear();
	bool flag = true;
			for(int n = 1 ; n <= 9 ; n++){
				for(int u = 0; u < 10 ; u++){
					for(int d = u ; d < 10 ; d++){
						if(u == d) continue;
						for(int i = 0 ; i < (1 << n); i++){
							num = 0; flag = true;
							for(int j = 0 ; j < n ; j++){
								if((i>>j)&1){
									num += d*pow(10,j);
								}else{
									num += u*pow(10,j);
								}
							}
							for(int k = 0 ; k < sol.size() ; k++){
								if(sol[k] == num){
									flag = false;
									break;
								}
							}
							if(flag){
								sol.push_back(num);
							}
						}
					}
				}
			}
	int display = 0;
	sol.push_back(1000000000);
	sort(sol.begin(),sol.end());
	for(int i = 1; i < sol.size() ; i ++){
		
		if(sol[i] > n){
			break;
		}else{
			display = i;
		}
		
		
	}
	cout << display << endl;
	return 0;
}
