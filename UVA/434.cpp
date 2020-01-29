#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int>a(n),b(n);
		for(int &i:a)cin >>i;
		for(int &i:b)cin >>i;
		sort(a.begin(),a.end()); sort(b.begin(),b.end());
		int mn = 0, mx = 0;
		for(int i = 0 ;i <= 8 ; i++){
			int a1 = 0, a2 = 0;
			for(int j : a){
				if(i==j) a1++;
			}
			for(int j : b){
				if(i==j) a2++;
			}
			mn += i*max(a1,a2);
		}
		for(int i : a){
			for(int j : b){
				mx += min(i,j);
			}
		}
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",mn,mx-mn);
	}
}
