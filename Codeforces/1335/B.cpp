#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
ll ar[N],p[N];
map<ll,ll> mp;
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        int n,a,b; cin >> n >> a >> b;
        string s;
        for(int i = 0; i < b ; i++){
            s += char(i+'a');
        }
        while(s.size() < a){
            s += s.back();
        }
        for(int i = 0 ; i < n ; i++){
            cout << s[i%s.size()];
        }
        cout << endl;
    }
	return 0;
}