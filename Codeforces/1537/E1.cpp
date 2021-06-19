#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n,k; cin >> n >> k;
  string s; cin >> s;
  vector<string> ans(n);
  for(int i = 0 ; i < n ; i++){
    string t = s.substr(0,i+1);
    ans[i] = "";
    for(int j = 0 ; j < (k+i)/(i+1) ; j++) ans[i] += t;
    while(ans[i].size() > k) ans[i].pop_back();
  }
  sort(ans.begin(),ans.end());
  cout << ans[0] << endl;
	return 0;
}