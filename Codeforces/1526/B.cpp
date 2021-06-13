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
    int x; cin >> x;
    if((x-111*(x%11))%11 == 0){
      cout << (x-111*(x%11) >= 0 ? "YES" : "NO") << endl;
    }else cout << "NO" << endl;
  }	
	return 0;
}
