#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 

int main(){
	int t; cin>>t;
	while(t--){
		int n,last = -6; cin>>n;
		bool ans=1;
		for(int i = 0 ; i < n; i++){
			int x; cin>>x;
			if(x){
				if(i-last<6) ans = 0;
				last = i;
			}
		}
		cout<<(ans?"YES":"NO") << endl;
	}
	return 0;
}