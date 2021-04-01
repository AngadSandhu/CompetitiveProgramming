#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
int a[N][3];
int main(){
	FIO;
	int n; cin >>  n;
  for(int i = 0 ; i < n ; i++) cin >> a[i][0];
  for(int i = 0 ; i < n ; i++) cin >> a[i][1];
  for(int i = 0 ; i < n ; i++) cin >> a[i][2];
  for(int i = 0 ; i < n ; i++){
    sort(a[i],a[i]+3);
    cout << a[i][1];
    if(i!=n-1) cout << " ";
  }
  cout << endl;
	return 0;
}