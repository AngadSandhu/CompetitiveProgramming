#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N
map<ll,pair<ll,ll>> mp;
int main(){
	FIO;
        ll n; cin >> n;
        vector<int> ar(n);
        for(int &i:ar) cin >> i;
        mp[0] = {0,0};
        ll sum = 0, res = 0;
        for(ll i = 0; i < n ; i++){
            sum += ar[i];
            if(mp.count(sum) > 0) res += (mp[sum].second - mp[sum].first + 1)*(n-i), mp.erase(sum);
            if(mp.count(sum) > 0) mp[sum] = {min(mp[sum].first,i),max(mp[sum].second,i)};
            else mp[sum] = {i,i};
        }
        cout << n*(n+1)/2 - res << endl;
	return 0;
}