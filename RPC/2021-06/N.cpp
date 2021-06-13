#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 500005
bool vis[N];
int a[N];
int main(){
	FIO;
	int n; cin >> n;
  set<int> st;
  for(int i = 1 ; i <= n ; i++){
    cin >> a[i];
    st.insert(i);
  }
  
  for(int i = 1 ;i <= n ; i++){
    while(vis[a[i]] == 1){
      a[i] = *st.begin();
      st.erase(st.begin());
    }
    vis[a[i]] = 1;
  }
  memset(vis,0,sizeof vis);
  vector<int> x,y;
  for(int i = 1 ; i <= n ; i++){
    if(vis[i]) continue;
    int curr = i, X = 0, Y;
    while(vis[curr] == 0){
      if(X < curr){
        X = curr;
        Y = a[curr];
      }
      vis[curr] = 1;
      curr = a[curr];
    }
    x.pb(X);
    y.pb(Y);
  }
  for(int i = 0 ; i < x.size() ; i++){
    a[x[i]] = y[(i+1)%x.size()];
  }
  for(int i = 1 ; i <= n ; i++) cout << a[i] << " "; cout << endl;
	return 0;
}