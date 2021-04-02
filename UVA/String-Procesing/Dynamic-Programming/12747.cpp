#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005

int lis(vector<int> &s){
  vector<int> d;
  for(int i = 0; i < s.size() ; i++){
    if(s[i] == -1) continue;
    int j = upper_bound(d.begin(),d.end(),s[i]) - d.begin();
    if(j == d.size()) d.pb(s[i]);
    else d[j] = s[i];
  }
  return d.size();
}
int s[N], t[N], sFlip[N];
int n,p,q;
int lcs(){
  for(int i = 0; i < n ; i++) sFlip[s[i]-1] = i;
  vector<int> s;
  for(int i = 0 ; i < n ; i++) s.pb(sFlip[t[i]-1]);
  return lis(s);
}
int main(){
	int T,caso = 0; cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> s[i];
    for(int i = 0 ; i < n ; i++) cin >> t[i];
    memset(sFlip,-1,sizeof sFlip);
    printf("Case %d: %d\n",++caso,2*(n-lcs()));
  }
	return 0;
}