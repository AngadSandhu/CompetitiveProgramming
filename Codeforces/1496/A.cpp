#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int maxPalin(string s){
  for(int i = 0 ; i < (s.size()-1)/2 ; i++){
    if(s[i] != s[s.size()-1-i]) return i;
  }
  return (s.size()-1)/2;
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int M = maxPalin(s);
    if(k==0 || k <= M){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
	return 0;
}