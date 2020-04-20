#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
vector<int> a;
bool isperm(int x,int j){
    vector<int> v;
    for(int i = x ; i <= j ; i++)  v.pb(a[i]);
    sort(v.begin(),v.end());
    for(int i = 1 ; i <= v.size() ; i++)
    if(v[i-1]!=i) return false;
    return true;
}
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int maxi = 0;
        a.resize(n);
        for(int &i : a) cin >> i, maxi = max(maxi,i);
        vector<pair<int,int>> ans;
        if(isperm(0,maxi-1) && isperm(maxi,n-1)) ans.pb({maxi,n-maxi});
        reverse(a.begin(),a.end());
        if(isperm(0,maxi-1) && isperm(maxi,n-1)) ans.pb({n-maxi,maxi});
        cout << ans.size() << endl;
        for(auto v : ans) cout << v.first << " " << v.second << endl; 
    }
	return 0;
}