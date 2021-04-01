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
	  pair<int,int> up = {-1,-1}, down = {-1,-1};
    int n; cin >> n;
    vector<int> a(n); 
    for(int &i : a) cin >> i;
    for(int i = 1 ; i < n ; i++){
      if(a[i-1] <= a[i]) up = {a[i-1],a[i]};
      if(a[i-1] > a[i]) down = {a[i-1],a[i]};
    }
    if(up.first == -1 || down.first == -1){
      if(n==1 || n==2){
        cout << 0 << endl;
      }else{
        set<int> st;
        for(int i = 1 ; i < n ; i++){
          st.insert(a[i]-a[i-1]);
        }
        if(st.size()==1) cout << 0 << endl;
        else cout << -1 << endl;
      }
      
    }
    else{
      int c = up.second-up.first;
      int m = down.first + c - down.second;
      bool ans = 1;
      if(a[0] >= m) ans = 0;
      for(int i = 1 ; i < n ; i++){
        if(a[i] != (a[i-1] + c)%m) ans = 0;
      }
      if(ans) cout << m << " " << c << endl;
      else cout << -1 << endl;
    }
  }
	return 0;
}