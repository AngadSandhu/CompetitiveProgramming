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
    string s,t; cin >> s >> t;
    for(int i = 0 ; i < n ; i++){
      if(t[i] != '1') continue;
      if(i!=0){
        if(s[i-1] == '1'){
          s[i-1] = '*';
          continue;
        }
      }
      if(s[i] == '0'){
        s[i] = '*';
        continue;
      }
      if(i!= n-1){
        if(s[i+1] == '1'){
          s[i+1] = '*';
          continue;
        }
      }
    }
    int ans = 0;
    for(int i = 0 ; i <n ; i++) ans += s[i]== '*';
    cout << ans << endl;
  }
	return 0;
}