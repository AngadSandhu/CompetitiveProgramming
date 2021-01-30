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
        int n;
        cin >> n;
        int f = 2020, s = 2021;
        bool found = 0;
        for(int i = 0 ; i <= n/f + 1; i++){
            for(int j = 0 ; j <= n/s + 1; j++){
                if(f*i + j*s == n){
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}