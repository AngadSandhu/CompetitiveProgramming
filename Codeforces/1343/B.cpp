#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n%4!=0){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
			for(int i = 0 ; i < n/2 ; i++){
				cout << 2*(i+1) << " ";
			}
			for(int i = 0 ; i < n/4 ; i++){
				cout << 2*i + 1 << " ";
			}
			for(int i = n/4 - 1; i >= 0 ; i--){
				cout << n+2 - (2*i + 1) << " ";
			}
			cout << endl;
		}
	}
	return 0;
}