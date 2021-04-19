#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000001
int x[N];
const int mod = 1000000;
int main(){
	FIO;
	x[0] = 1;
  for(int i = 1 ; i < N ; i++){
    int a = (int)(1.0*i - sqrt(i));
    int b = (int)log(i);
    int c = (int)(1.0*i*sin(i)*sin(i));
    x[i] = x[a] + x[b] + x[c];
    x[i] %= mod;
  }
  int ask;
  while(cin >> ask, ask >= 0) cout << x[ask] << endl;
	return 0;
}