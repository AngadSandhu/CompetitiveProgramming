#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int BIT[N];
int n,k;
void add(int pos){
  for(int i = pos ; i <= n ; i+=i&-i) BIT[i]++;
}
int query(int pos){
  int ret = 0;
  for(int i = pos ; i > 0 ; i-=i&-i) ret += BIT[i];
  return ret;
}
pair<int,int> points[N];
bool comp(pair<int,int> p1, pair<int,int> p2){
  return p1.second < p2.second;
}
unordered_map<int,int> mp;
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> points[i].first >> points[i].second;
    sort(points,points+n,comp);
    for(int i = 0 ; i < n ; i++){
      if(mp.count(points[i].second) == 0) mp[points[i].second] = mp.size()+1;
    }
    sort(points,points+n);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      int d = query(mp[points[i].second]);
      if(abs(2*d-n+1) >= k) ans++;
      add(mp[points[i].second]);
    }
    cout << ans << endl;
    for(int i = 0 ; i <= n ; i++) BIT[i] = 0;
    mp.clear();
  }
	return 0;
}