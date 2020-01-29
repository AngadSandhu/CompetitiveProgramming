#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin >> t;
	while(t--){
		ll n,nn; cin >> n;
		nn = n;
		vector<int>desc;
		while(n>0){
			desc.push_back(n%3);
			n/=3;
		}
		desc.push_back(0);
		int two = -1;
		for(int i = 0 ; i < desc.size() ; i++){
			if(desc[i]==2) two = i;
		}
		if(two!=-1){
			ll ans = 0;
			for(int i = two+1 ; i < desc.size() ; i++){
				if(desc[i]==0){
					desc[i] = 1;
					for(int j = i ; j< desc.size() ;j++){
						ans += desc[j]*(ll)pow(3,j);
					}
					break;
				}
			}
			cout<< ans << endl;
		}else{
			cout << nn << endl;	
		}
	}
	return 0;
}
