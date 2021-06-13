#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005
struct Block{
  int l;
  string s;
  Block(){};
  void cinBlock(){
    cin >> s >> l;
  };
};
bool vis[N];
bool comp(Block b1, Block b2){
  return (b1.s == "cube" ? b1.l*sqrt(2) : b1.l*2) < (b2.s == "cube" ? b2.l*sqrt(2) : b2.l*2);
}
int main(){
	FIO;
  int n; cin >> n;
  vector<Block> a(n);
  for(int i = 0 ; i < n ; i++) a[i].cinBlock();
  bool impossible = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0; j < n ; j++){
      if(a[i].s != a[j].s && a[i].s == "cylinder"){
        if(1.0*a[j].l/2 < a[i].l && a[i].l < 1.0*a[j].l*sqrt(2)/2) impossible = 1;
      } 
    }
  }
  if(impossible) cout << "impossible" << endl;
  else{
    sort(a.begin(),a.end(),comp);
    for(int i = 0 ; i < n ; i++){
      cout << a[i].s << " " << a[i].l << endl;
    }
  }
	return 0;
}