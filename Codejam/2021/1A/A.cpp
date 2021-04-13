#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
  int caso = 0;
  while(t--){
    int n; cin >> n;
    vector<string> a(n);
    for(auto &i  : a) cin >> i;
    int ans = 0;
    for(int i = 1 ; i < n ; i++){
      if(a[i-1].size()  == a[i].size()){
        if(a[i] <= a[i-1]){
          a[i] += '0';
          ans++;
        }
      }else if(a[i-1].size()  > a[i].size()){
        if(a[i] > a[i-1].substr(0,a[i].size())){

          ans += a[i-1].size()-a[i].size();
          a[i] += string(a[i-1].size()-a[i].size(),'0');

        }else if(a[i] < a[i-1].substr(0,a[i].size())){

          ans += a[i-1].size()-a[i].size()+1;
          a[i] += string(a[i-1].size()-a[i].size()+1,'0');

        }else{
          int idx = -1;
          for(int j = a[i-1].size()-1 ; j >= a[i].size() ; j--){
            if(a[i-1][j] != '9'){
              idx = j;
              break;
            }
          }
          if(idx == -1){
            ans += a[i-1].size()-a[i].size()+1;
            a[i] += string(a[i-1].size()-a[i].size()+1,'0');
          }else{
            ans += a[i-1].size()-a[i].size();
            for(int j = a[i].size() ; j < idx ; j++) a[i] += a[i-1][j];
            a[i] += char(a[i-1][idx]+1);
           
            a[i] += string(a[i-1].size()-a[i].size(),'0');
          }
        }
      }
      // cout << i << " " << a[i] << endl;
    }
    cout << "Case #" << ++caso << ": " << ans << endl;
  }
	return 0;
}