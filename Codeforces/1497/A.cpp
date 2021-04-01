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
    int n; cin >> n;
    vector<int> a(n), frec(105);
    set<int> st;
    for(int & i: a) cin >> i, frec[i]++, st.insert(i);
    for(auto x: st) cout << x << " ";
    for(int i = 0 ; i < frec.size() ; i++){
      for(int j = 1 ; j < frec[i] ; j++){
        cout << i << " ";
      }
    }
    cout << endl;
  }
	return 0;
}