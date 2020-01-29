#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int main(){
	cin >> n >> k;
	int mx = -1,ans = 0;
	for(int i = 0 ; i <= k ; i ++){
		cout << "? ";
		for(int j = 0 ; j <= k ; j++){
			if(j!=i) cout << j+1 << " ";
		}
		cout << endl;
		int num,pos; cin >> pos >> num;
		if(mx <= num){
			if(mx < num) ans = 0;
			ans++;
			mx = num;
		}
	}
	cout << "! " << ans << endl;
	return 0;
}
