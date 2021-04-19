#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 505
int C;
bool taken[N];
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    memset(taken,0,sizeof taken);
    int n,l,r,s; cin >> n >> l >> r >> s;
    C = r-l+1;
    if(s < C*(C+1)/2 || s > n*(n+1)/2 -(n-C)*(n-C+1)/2){
      cout << -1 << endl;
      continue;
    }
    ll sum = 0;
    for(int i = 1 ; i <= C ; i ++){
      sum += i;
      taken[i] = 1;
    }
    while(sum < s){
      for(int i = 1 ; i < n && sum < s; i++){
        if(taken[i] == 1 && taken[i+1] == 0){
          taken[i] = 0;
          taken[i+1] = 1;
          sum++;
        }
      }
    }
    vector<int> toPrint, notPrint;
    for(int i = 1 ; i <= n ; i++){
      if(taken[i]) toPrint.pb(i);
      else notPrint.pb(i);
    }
    for(int i = 1 ; i < l ; i++){
      cout << notPrint.back() << " ";
      notPrint.pop_back();
    }
    for(int i = l ; i <= r ; i++){
      cout << toPrint.back() << " ";
      toPrint.pop_back();
    }
    for(int i = r+1 ; i <= n ; i++){
      cout << notPrint.back() << " ";
      notPrint.pop_back();
    }
    cout << endl;
  }
	return 0;
}