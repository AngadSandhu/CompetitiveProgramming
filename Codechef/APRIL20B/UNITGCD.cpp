#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 1000005
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
int main(){
	FIO;
	int t; cin>>t;
	while(t--){
		int n; cin >> n;
		if(n<4){
			cout << 1 << "\n";
			cout << n << " ";
			for(int i = 1 ; i <= n ; i++) cout << i << " ";
			cout << "\n";
		}else{
			cout << n/2 << "\n";
			if(n%2){
				cout << "3 1 2 3\n";
				for(int i = 4 ; i <= n ; i+=2){
					cout << 2 << " " << i << " " << i+1 << "\n";
				}
			}else{
				cout << "2 1 2\n";
				for(int i = 3 ; i <= n ; i+=2){
					cout << 2 << " " << i << " " << i+1 << "\n";
				}
			}
		}
	}
	return 0;
}