#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
bool checkOne(string &s,int pos){
  int n = s.size();
  for(int i = 1 ; i <= pos ; i++){
    if(s[i] == s[i-1] && s[i]=='1') return false;
  }
  for(int i = pos+2 ; i < n ; i++){
    if(s[i] == s[i-1] && s[i]=='0') return false;
  }
  if(s[pos] == '1' && s[pos+1] == '0') return false;
  return true;
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    string s; cin >> s;
    bool ans = 0;
    set<char> st;
    for(int i = 0 ; i< s.size() && !ans; i++){
      if(checkOne(s,i)) ans = 1;
      st.insert(s[i]);
      //cout << i << " " << ans << endl;
    }
    ans |= st.size()==1 ;
    cout << (ans? "YES" : "NO") << endl;
  }
	return 0;
}