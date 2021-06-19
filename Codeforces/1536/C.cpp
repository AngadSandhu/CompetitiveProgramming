#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
map<pair<int,int>,int> mp;
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int d = 0, k =0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      if(s[i] == 'D') d++;
      else k++;
      mp[{d/__gcd(d,k),k/__gcd(d,k)}]++;
      cout << mp[{d/__gcd(d,k),k/__gcd(d,k)}] << " ";
    }
    cout << endl;
    mp.clear();
  }
	return 0;
}