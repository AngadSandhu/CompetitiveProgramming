#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define M 205
#define N 200005
int freq[M][N];
int ar[N];
vector<int> v[M];
int get(int l,int r){
    if(l > r) return 0;
    int ret = INT_MIN;
    for(int i = 0 ; i < M ; i++){
        ret = max(ret,freq[i][r+1] - freq[i][l]);
    }
    return ret;
}
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++) cin >> ar[i], v[ar[i]].pb(i);
        for(int i = 0 ; i < M ; i++) freq[i][0] = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < M ; j++){
                freq[j][i] = freq[j][i-1];
                if(ar[i-1] == j) freq[j][i]++;
            }
        }
        int ans = INT_MIN, l, r;
        for(int i = 0 ; i < M ; i++){
            int m = v[i].size();
            l = 0, r = m-1;
            while(l < r){
                ans = max(ans, l + 1 + m - r + get(v[i][l]+1,v[i][r]-1));
                l++, r--;
            }
        }
        cout << (ans==INT_MIN?1:ans) << endl;
        for(int i = 0 ; i < M ; i++) v[i].clear();
    }
	return 0;
}