#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
  int caso = 1;
  while(t--){
    int x,y; cin >> x >> y;
    string s; cin >> s;
    s.resize(unique(s.begin(),s.end())-s.begin());
    int n = s.size();
    int ans = 0;
    for(int i = 1 ; i < n ; i++){
      if(s[i]=='?'){
        s[i] = s[i-1];
      }else{
        if(s[i-1]=='J' && s[i] == 'C') ans += y;
        else if(s[i-1]=='C' && s[i] == 'J') ans += x;
      }
    }
    cout << "Case #" << caso++ << ": " << ans << endl;
  }
	return 0;
}