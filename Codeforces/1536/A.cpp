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
    vector<int> a(n);
    int cnt = 0, maxi = 0;
    for(int &i : a) cin >> i, cnt += (i<0), maxi = max(maxi,i);
    if(cnt > 0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
      cout << maxi+1 << endl;
      for(int i = 0 ; i <= maxi ; i++) cout << i << " "; cout << endl;
    }
  }
	return 0;
}