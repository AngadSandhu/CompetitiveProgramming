#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ar[305];
ll res = 0;
bool pos = 1;
int main(){
	int t; cin >> t;
	while(t--){
		pos = 1;
		cin >> n;
		for(int i = 0 ; i < n ; i++) cin >> ar[i];
		sort(ar,ar+n);
		res = ar[n-1]*ar[0];
		for(int i = 0 ; i <= n/2 ; i++){
			if(n%2==1 && i == n/2){
				pos &= (res==(ar[i]*ar[i]));
				res = ar[i]*ar[i];
			}else{
				pos &= (res==(ar[n-i-1]*ar[i]));
				res = (ar[n-i-1]*ar[i]);
			}
		}
		int cnt = 0;
		for(ll i = 2 ; i*i <= res ; i++){
			if(res%i==0) cnt+=2;
			if(i*i==res) cnt--;
		}
		if(cnt!=n) pos = 0;
		cout << (pos?res:-1) << endl;
	}
	return 0;
}
