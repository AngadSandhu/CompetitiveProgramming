#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 300005
typedef unsigned long long Hash;
Hash H[N], P[N];
int k = 31;
int n;
string s;
Hash gethash(int l,int r){
	return H[r] - P[r-l]*H[l];
}
int f(int t){
  set<Hash> st, repeated;
  for(int i = 0 ; i <= n-t ; i++){
    if(st.find(gethash(i,i+t)) != st.end()) repeated.insert(gethash(i,i+t));
    st.insert(gethash(i,i+t));
  }
  int ret = -1;
  for(int i = 0 ; i <= n-t ; i++){
    if(repeated.find(gethash(i,i+t)) == repeated.end()){ // no esta repetido
      ret = i;
      break;
    }
  }
  return ret;
}
string solve(){
  int l = 1, r = n, med;
  while(l < r){
    med = (l+r)/2;
    if(f(med) != -1) r = med;
    else l = med+1;
  }
  return s.substr(f(l),l);
}
int main(){
	FIO;
  cin >> s;
  n = s.size();
	H[0] = 0;
  P[0] = 1;
  for(int i = 1 ; i <= n ; i++){
    H[i] = H[i-1]*k + (s[i-1]-'A'+1);
    P[i] = P[i-1]*k;
  }
  cout << solve() << endl;
	return 0;
}