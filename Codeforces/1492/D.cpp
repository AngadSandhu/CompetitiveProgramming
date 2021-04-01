#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int a,b,k;
int main(){
	FIO;
	cin >> a >> b >> k;
  if(a==0 && k != 0){
    cout << "No"<< endl;
    return 0;
  }
  if(b==1 && k != 0){
    cout << "No"<< endl;
    return 0;
  }
  if(k==0){
    cout << "Yes" << endl;
    for(int i = 0 ; i < b ; i++){
      cout << "1";
    }
    for(int i = 0 ; i < a ; i++){
      cout << "0";
    }
    
    cout << endl;
    for(int i = 0 ; i < b ; i++){
      cout << "1";
    }
    for(int i = 0 ; i < a ; i++){
      cout << "0";
    }
    
    cout << endl;
    return 0;
  }
  if(a + b - 2 < k){
    cout << "No"<< endl;
  }else{
    cout << "Yes" << endl;
    int need = max(k-a,0);
    vector<pair<int,int>> v;
    v.pb({1,1});
    for(int i = 0 ; i < b-need-2 ; i++){
      v.pb({1,1});
    }
    v.pb({1,0});
    for(int i = 0 ; i < k-need-1 ; i++){
      v.pb({0,0});
    }
    for(int i = 0 ; i < need ; i++){
      v.pb({1,1});
    }
    v.pb({0,1});
    for(int i = 0 ; i < max(a-k,0) ; i++){
      v.pb({0,0});
    }
    for(int i = 0 ; i < v.size() ; i++){
      cout << v[i].first;
    }
    cout << endl;
    for(int i = 0 ; i < v.size() ; i++){
      cout << v[i].second;
    }
    cout << endl;
  }
	return 0;
}