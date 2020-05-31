#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    if(n > m){
        cout << 0 << endl;
    }else{
        ll ans = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                ans = (ans * abs(a[i]-a[j]))%m;
            }
        }
        cout << ans << endl;
    }
	return 0;
}