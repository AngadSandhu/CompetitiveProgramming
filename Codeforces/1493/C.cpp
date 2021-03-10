#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int n,k;
string s;
bool isDone(){
  vector<int> frec(26,0);
  for(auto c : s) frec[c-'a']++;
  for(auto i : frec){
    if(i%k != 0) return false;
  }
  return true;
}

string solve(){
  vector<int> frec(26,0);
  for(int i = 0; i < n ; i++) frec[s[i]-'a']++;
  for(int i = n-1 ; i >= 0 ; i--){
    frec[s[i]-'a']--;
    for(char j = s[i]+1; j <= 'z' ; j++){
      int left = n-i-1, need = 0;
      frec[j-'a']++;
      for(int jj = 0 ; jj < 26 ; jj++){
        int now = (k-frec[jj]%k)%k;
        need += now;
      }
      if(left<need){
        frec[j-'a']--;
        continue;
      }
      if((left-need)%k == 0){
        string sAns = "";
        sAns += string(left-need,'a');
        for(int jj = 0 ; jj < 26 ; jj++){
          int now = (k-frec[jj]%k)%k;
          sAns += string(now,char(jj+'a'));
        }
        return s.substr(0,i) + j + sAns;
      }
      frec[j-'a']--;
    }
  }
  return "-1";
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    cin >> n >> k >> s;
    if(isDone()){
      cout << s << endl;
      continue;
    }
    string ans = solve();
    cout << solve() << endl;
  }
	return 0;
}