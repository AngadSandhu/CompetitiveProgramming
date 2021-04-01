#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define MAXN 10000001
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}
int main(){
	FIO;
  sieve();
	int t; cin >> t;
  while(t--){
    ll n,k ; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    for(int i = 0 ; i < n ; i++){
      vector<int> fac;
      while (a[i] > 1){
        int cur = spf[a[i]], cnt = 0;
        while(a[i] % cur == 0){
          a[i] /= cur;
          cnt++;
        }
        if(cnt%2) fac.pb(cur);
      }
      a[i] = 1;
      for(int j = 0 ; j < fac.size() ; j++){
        a[i] *= fac[j];
      }
    }
    int ans = 0;
    set<int> st;
    for(int i = 0 ; i < n ; i++){
      if(st.find(a[i]) != st.end()){
        ans++;
        st.clear();
      }
      st.insert(a[i]);
    }
    cout << ans + 1 << endl;
  }
	return 0;
}