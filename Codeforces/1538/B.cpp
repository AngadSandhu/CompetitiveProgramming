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
    for(int &i:a) cin >> i;
    sort(a.begin(),a.end());
    ll sum_need = 0, sum = 0, x = -1;
    for(int i = 0 ; i < n ; i++) sum += a[i];
    if(sum % n != 0){
      cout << -1 << endl;
      continue;
    }
    x = sum/n;
    int k = 0;
    for(int i = n-1; i >= 0 ; i--){
      if(a[i] > x) k++;
      else break;
    }
    cout << k << endl;
  }
	return 0;
}