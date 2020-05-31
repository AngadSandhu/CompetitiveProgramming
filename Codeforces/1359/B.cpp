#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
char a[N][N];
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        int n,m,x,y; cin >> n >> m >> x >> y;
        int c1 = x, c2 = min(2*x,y);
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            string s; cin >> s;
            for(int j = 0 ; j < m ; j++){
                if(j < m-1 && s[j]=='.' && s[j+1]=='.') ans += c2, j++;
                else if(s[j]=='.') ans += c1;
            }
        }
        cout << ans << endl;
    }
	return 0;
}