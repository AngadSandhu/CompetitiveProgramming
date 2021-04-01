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
    vector<int> a(n),b(n),t(n),takes(n), need(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i];
    for(int i = 0 ; i < n ; i++) cin >> t[i];
    for(int i = 0 ; i < n ; i++){
      takes[i] = a[i] - (i==0 ? 0 : b[i-1]) + t[i];
      need[i] = (b[i]-a[i] + 1)/2;
    }
    int ans = 0, curar = 0, curbr = 0;
    for(int i = 0 ; i < n ; i++){
      curar = curbr + takes[i];
      curbr = max(b[i],curar + need[i]);
    }
    cout << curar << endl;
  }
	return 0;
}