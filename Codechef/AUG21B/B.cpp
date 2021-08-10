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
    vector<int> a(4);
    for(int &i:a) cin >> i;
    sort(a.begin(),a.end());
    if(a[0] == a[1] && a[2] == a[3]){
      if(a[1] != a[2]) cout << 2 << endl;
      else cout << 0 << endl;
    }else if(a[0] == a[1] && a[1] == a[2] && a[2] != a[3]){
      cout << 1 << endl;
    }else if(a[0] != a[1] && a[1] == a[2] && a[2] == a[3]){
      cout << 1 << endl;
    }else{
      cout << 2 << endl;
    }
  }
	return 0;
}