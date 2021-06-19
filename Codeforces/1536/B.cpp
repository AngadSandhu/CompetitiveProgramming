#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
set<string> st;
string plus1(string s){
  int n = s.size();
  if(s.back() == 'z'){
    while(s.back() == 'z') s.pop_back();
    if(s.empty()) return string(n+1,'a');
    s.back()++;
    while(s.size() < n) s.push_back('a');
  }else{
    s.back()++;
  }
  return s;  
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0 ; i < n ; i++){
      for(int j = 1 ; j <= n ; j++){
        st.insert(s.substr(i,j));
      }
    }
    string t = "a";
    while(t.size() <= 3){
      if(st.find(t) == st.end()){
        cout << t << endl;
        break;
      }
      t = plus1(t);
    }
    st.clear();
  }
	return 0;
}