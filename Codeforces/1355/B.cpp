#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n),freq(n+1,0);
        for(int &i : a) cin >> i, freq[i]++;
        sort(a.begin(),a.end());
        int ans = 0;
        int res = 0;
        for(int i = 1 ; i <= n ; i++){
            ans += (freq[i]+res)/i;
            res = (freq[i]+res)%i;
        }
        cout << ans << endl;
    }
	return 0;
}