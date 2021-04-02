#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
  int test = 0;
  while(true){
    vector<int> v;
    int x;
    while(cin >> x, x >= 0) v.pb(x);
    if(v.empty()) break;
    reverse(v.begin(),v.end());
    vector<int> lis;
    for(int i = 0 ; i < v.size() ; i++){
      int j = upper_bound(lis.begin(),lis.end(),v[i]) - lis.begin();
      if(j == lis.size()) lis.pb(v[i]);
      else lis[j] = v[i];
    }
    if(test > 0) cout << endl;
    printf("Test #%d:\n  maximum possible interceptions: %d\n",++test,(int)lis.size());
  }
	return 0;
}