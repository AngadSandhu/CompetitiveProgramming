#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n,m; cin >> m >> n;
  int ans = n-1 + m/(1<<(n-1));
  int maxi = min(m-1,(1<<n)-1);
  int mini = min(maxi,m-maxi);
  cout << mini << " " << maxi << endl;
  cout << ans << endl;
	return 0;
}