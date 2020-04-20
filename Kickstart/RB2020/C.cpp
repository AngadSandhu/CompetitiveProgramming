#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int const mod = 1e9;
int main(){
	FIO;
	int t,caso = 0; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        ll r = 0, c = 0;
        stack<ll> q;
        q.push(1);
        for(int i = 0 ; i < n ; i++){
            if(s[i]==')') q.pop();
            else if(s[i] <= '9' && s[i] >= '0'){ q.push(((s[i]-'0')*q.top())%mod), i++; continue; }
            else if(s[i] == 'N') r = (r-q.top()+mod)%mod;
            else if(s[i] == 'S') r = (r+q.top()+mod)%mod;
            else if(s[i] == 'E') c = (c+q.top()+mod)%mod;
            else if(s[i] == 'W') c = (c-q.top()+mod)%mod;
        } 
        cout << "Case #" << ++caso << ": " << c+1 << " " << r+1 << endl;
        q.pop();
    }
	return 0;
}