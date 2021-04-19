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
    int a,b; cin >> a >> b;
    string s; cin >> s;
    int n = s.size();
    int free = 0;
    for(int i = 0 ; i < n ; i++){
      if(s[i] != '?' && s[n-i-1] == '?') s[n-i-1] = s[i];
    }

    for(int i = 0 ; i < n ; i++){
      if(s[i] == '0') a--;
      else if(s[i] == '1') b--;
    }

    if(s[n/2] == '?' && n%2){
      if((a%2 && b%2) || (a%2==0 && b%2==0)){
        cout << -1 << endl;
        continue;
      }
    }else{
      if(!(a%2==0 && b%2==0) ){
        cout << -1 << endl;
        continue;
      }
    }
    for(int i = 0; i < n ; i++){
        if(s[i] == '?'){
          if((a >= 2 && i!=n-i-1) || (a > 0 && i == n-i-1)){
            s[i] = '0';
            s[n-i-1] = '0';
            a--;
            if(i != n-i-1) a--;
          }else{
            s[i] = '1';
            s[n-i-1] = '1';
            b--;
            if(i != n-i-1) b--;
          }
        }
    }

    bool notSolv = 0;
    for(int i = 0 ; i < n ; i++){
      if(s[i] != '?' && s[n-i-1] != '?' && s[i] != s[n-i-1]){
        notSolv = 1;
        break;
      }
    }
    if(notSolv || a > 0 || b > 0){
      cout << -1 << endl;
      continue;
    }
    cout << s << endl;
  }
	return 0;
}