#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n; cin >> n;
    vector<double> p(n);
    bool flag = 0;
    for(auto &i : p) cin >> i, flag |= i > 1 - 1e-9;
    if(flag){
        cout << 1 << endl;
        return 0;
    }
    sort(all(p));
    long double ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            long double prima = 1, cur = 0;
            for(int k = i ; k <= j ; k++) prima *= (1-p[k]);
            for(int k = i ; k <= j ; k++) cur += prima * (p[k]/(1-p[k]));
            ans = max(ans,cur);
        }
    }
    cout << fixed << setprecision(9) << ans << endl;
	return 0;
}