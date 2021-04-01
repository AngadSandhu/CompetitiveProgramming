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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    map<int,int> frec;
    map<int,bool> vis;
    for(int &i : a) cin >> i, frec[i%m]++;
    int ans = 0;
    for(auto x : frec){
      if(vis[x.first] == 1) continue;
      if(x.first == 0 || (x.first == m/2 && m%2==0)){
        ans += 1;
        vis[x.first] = 1;
      }else{
        int a = x.second;
        int b = frec[m-x.first];
        int par = min(a,b) + (a!=b);
        ans += max(a,b) - par + 1;
        vis[x.first] = 1;
        vis[m-x.first] = 1;
        //cout << x.first << " " <<a << " " << b <<  " " << max(a,b) - par + 1 << endl; 
      }
    }
    cout << ans << endl;
  }
	return 0;
}