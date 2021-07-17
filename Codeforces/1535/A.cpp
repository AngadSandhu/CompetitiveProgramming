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
    vector<pair<int,int>> a(4);
    for(int i = 0 ; i < 4 ; i++){
      cin >> a[i].first, a[i].second = i;
    }
    sort(a.begin(),a.end());
    if(a[2].second < 2 && a[3].second < 2 || a[2].second >= 2 && a[3].second >= 2)
    cout << "NO" << endl;
    else cout << "YES" << endl;
  }
	return 0;
}