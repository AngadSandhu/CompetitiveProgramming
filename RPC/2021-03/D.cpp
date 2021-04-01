#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n; cin >> n;
  ll sum = 0;
  for(int i = 0 ; i< n ; i++){ int x; cin >> x; sum += x; }
  cout << (sum%3==0 ? "yes" : "no") << endl;
	return 0;
}