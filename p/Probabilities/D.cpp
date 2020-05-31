#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 5005
string s;
ll n;
int f[26][N][26];
int main(){
	FIO;
	cin >> s;
    n = s.size();
    s += s;
    for(int i = 0 ; i < n ; i++) for(int j = i+1 ; j < n + i ; j++) f[s[i]-'a'][j-i][s[j]-'a']++;
    ll ans = 0;
    for(int i = 0 ; i < 26 ; i++){
        ll cur = 0;
        for(int j = 1 ; j < n ; j++){
            ll c2 = 0;
            for(int k = 0 ; k < 26 ; k++){
                if(f[i][j][k]==1) c2++;
            }
            cur = max(cur,c2);
        }
        ans += cur;
    }
    cout << fixed << setprecision(6) << (long double)ans/n << endl;
	return 0;
}