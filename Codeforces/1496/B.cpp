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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end())-a.begin());
    n = a.size();
    int mex = 0, maxi = a[n-1];
    for(int i = 0 ; i < n ; i++){
      if(a[i]==mex) mex++;
    }
    //cout << mex << " " << maxi << endl;
    if(mex==n){
      cout << n+k << endl;
    }else if((mex+maxi+1)/2 == maxi){
      cout << n << endl;
    }else{
      bool ans = 0;
      for(int i = 0 ; i < n ; i++) ans |= a[i] == (mex+maxi+1)/2;
      cout << n + min(k,(int)!ans) << endl;
    }
  }	
	return 0;
}