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
    ll a,b,k; cin >> a >> b >> k;
    ll sum_min = 0, sum = 0;
    for(ll i = 2 ; i * i <= a || i * i <= b ; i++){
      if(a%i == 0 || b%i == 0){
        int cnt1 = 0, cnt2 = 0;
        while(a%i == 0){
          a /= i;
          cnt1++;
        }
        while(b%i == 0){
          b /= i;
          cnt2++;
        }
        sum += cnt1 + cnt2;
        sum_min += min(cnt1,cnt2);
      }
    }
    if(a == b && a > 1) sum++, sum_min++;
    else if(a > 1 || b > 1) sum+=2, sum_min+=2;
    ll Km = sum - 2*sum_min, KM = sum;
    // cout << Km << " " << KM << " " << endl;
    if(k < KM) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
	return 0;
}