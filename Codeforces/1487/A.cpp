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
    for(int &i : a) cin >> i;
    sort(a.begin(),a.end());
    int mini = a[0], cnt = 0;
    for(int i = 0 ; i < n ; i++){
      if(a[i]==mini) cnt++;
    }
    cout << n-cnt << endl;
  }
	return 0;
}