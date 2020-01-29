#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        ll sum = 0;
        vector<ll> v(n);
        for(int i = 0 ; i <  n ; i++){
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(),v.end());
        if(m < n || n<=2) cout << -1 << endl;
        else{
            cout << 2*sum << endl;
            for(int i = 0 ; i < n ; i++){
                cout << i%n + 1 << " " << (i+1)%n + 1<< endl;
            }
        }
    }
    return 0;
}