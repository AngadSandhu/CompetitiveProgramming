#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            c += (s[i]=='1');
        }
        if(c==0){
            cout << 0 << endl;
            continue;
        }
        vector<bool> flag(k);
        vector<int> ceros(k), count(k);
        for(ll i = n-1 ; i >= 0 ; i--){
            if(s[i]=='1') flag[i%k] = 1;
            if(flag[i%k]) ceros[i%k] += (s[i]=='0'), count[i%k]++;
            cur += (s[i]=='1');
            //cout << pref[i] << " "<< cur << " " << suf[i%k]<< endl;
            mini = min(mini, pref[i] + ceros[i%k] + cur - suf[i%k]);
        }
        cout << mini << endl;
    }
	return 0;
}