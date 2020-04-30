#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
vector<int> res[N];
int main(){
	FIO;
    int n,k;
    cin >> n >> k;
    vector<int> v(n),may(k),c(k);
    for(int &i:v) cin >> i, may[i-1]++;
    for(int &i:c) cin >> i;
    sort(v.begin(),v.end());
    for(int i = k-2 ; i >= 0 ; i--){
        may[i] += may[i+1];
    }
    int ans = INT_MIN;
    for(int i = 0 ; i < k ; i++){
        ans = max(ans,(may[i]+c[i]-1)/c[i]);
    }
    for(int i = 0 ; i < n ; i++){
        res[i%ans].pb(v[i]);
    }
    cout << ans << endl;
    for(int i = 0 ; i < ans ; i++){
        cout << res[i].size() << " ";
        for(auto x : res[i]) cout << x << " ";
        cout << endl;
    }
    
	return 0;
}