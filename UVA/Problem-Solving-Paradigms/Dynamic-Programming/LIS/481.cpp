#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int main(){
	FIO;
	vector<int> v;
  int x;
  while(cin >> x) v.pb(x);
  vector<int> lis;
  vector<vector<int>> lisIndex;
  for(int i = 0; i < v.size() ; i++){
    int j = lower_bound(lis.begin(),lis.end(),v[i]) - lis.begin();
    if(j == lis.size()){
      lis.pb(v[i]);
      vector<int> newV(1,i);
      lisIndex.pb(newV);
    }else{
      lis[j] = v[i];
      lisIndex[j].pb(i);
    }
  }
  // for(int i = 0 ; i < lis.size(); i++){
  //   cout << "i: " << i << endl;
  //   for(int j = 0 ; j < lisIndex[i].size() ; j++){
  //     cout << lisIndex[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << lis.size() << endl;
  cout << "-" << endl;
  vector<int> lisConstruction;
  int last = lisIndex[lis.size()-1].back();
  lisConstruction.pb(last);
  for(int i = lis.size()-2 ; i >= 0; i--){
    int j = lisIndex[i].size()-1;
    while(j > 0 && lisIndex[i][j] >= last) j--;
    last = lisIndex[i][j];
    lisConstruction.pb(last);
  }
  reverse(lisConstruction.begin(),lisConstruction.end());
  for(auto i : lisConstruction) cout << v[i] << endl;
	return 0;
}