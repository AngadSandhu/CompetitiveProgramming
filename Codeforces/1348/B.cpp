#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10000

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        set<int> st;
        for(int i = 0 ; i < n ; i++){
            int x; cin >> x;
            st.insert(x);
        }
        if(st.size() > k){
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        for(auto v : st){
            ans.pb(v);
        }
        while(ans.size() < k) ans.pb(1);
        cout << n*(int)ans.size() << endl;
        for(int i = 0 ; i < n ; i++) for(auto v : ans) cout << v << " ";
        cout << endl;
    }
	return 0;
}