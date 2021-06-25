#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
int n,d[N];
vector<pair<int,int>> bit[N];
void update(int id, int x,int val){
  for(int i = x ; i < N ; i += i&(-i)){
    int acum = 0;
    if(bit[i].size() > 0) acum = bit[i].back().second;
    bit[i].pb({id,acum + val});
  }
}
int query(int id, int x){
  int ret = 0;
  for(int i = x ; i > 0 ; i -= i&-i){
    if(bit[i].size() == 0) continue;
    int pos = upper_bound(bit[i].begin(),bit[i].end(),make_pair(id,-1)) - bit[i].begin();
    if(pos-1 < 0) continue;
    ret += bit[i][pos-1].second;
  }
  return ret;
}

int main(){
	FIO;
	cin >> n;
  cin.ignore();
  string s;
  for(int i = 0 ; i < n ; i++){
    getline(cin,s);
    stringstream in(s);
    char c;
    int x;
    while(in >> c){
      in >> x;
      if(c=='+') update(i+1,x+1,1);
      else update(i+1,x+1,-1);
    }
  }
  for(int i = 0 ; i < n ; i++){
    cin >> d[i];
  }
  int x = 0;
  for(int i = 0 ; i < n ; i++){
    x = (x + query(d[i],N-1) - query(d[i],x+1))%n;
  }
  cout << x << endl;
	return 0;
}