#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> a(n), b;
        for(int &i:a) cin >> i;
        for(int i = 0 ; i < k ; i++) b.pb(a[i]);
        for(int i = k ; i < n ; i++){
            while(b.size() < N && a[i] != b[b.size()-k]) b.pb(b[b.size()-k]);
            b.pb(a[i]);
        }
        if(b.size() > N) cout << -1 << endl;
        else{
            cout << b.size() << endl;
            for(auto x : b) cout << x << " ";
            cout << endl;
        }
    }
	return 0;
}