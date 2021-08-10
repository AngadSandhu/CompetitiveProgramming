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
    int a,b,c; cin >> a >> b >> c;
    int sum1 = 0, sum2 = 0;
    sum1 = a + b + c;
    cin >> a >> b >> c;
    sum2 = a + b + c;
    cout << (sum1<sum2 ? "2" : "1") << endl;
  }	
	return 0;
}