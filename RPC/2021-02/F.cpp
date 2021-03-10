#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 


int main(){
	FIO;
  int n; cin >> n;
  vector<pair<int,int>> k(n);
  for(int i =0 ; i < n ; i++){
    int x; cin >> x;
    k[i] = {i,x};
  }
  int curr = 0,newPos=0, sz = k.size();
  while(k.size() != 1){
    sz = k.size();
    newPos = ((curr+k[curr].second)%sz-1+sz)%sz;
    k.erase(k.begin() + newPos);
    if(newPos==sz-1) curr = 0;
    else curr = newPos;
  }
  cout << k[0].first+1 << endl;
	return 0;
}