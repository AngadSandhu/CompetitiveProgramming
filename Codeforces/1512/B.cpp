#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 405
char ar[N][N];
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    pair<int,int> a = {-1,-1},b = {-1,-1};
    for(int i = 0 ; i  < n ; i++){
      for(int j = 0 ; j < n ; j++){
        cin >> ar[i][j];
        if(ar[i][j] == '*'){
          if(a == make_pair(-1,-1)) a = {i,j};
          else b = {i,j};
        }
      }
    }
    if(a.first == b.first){
      if(a.first == n-1){
        ar[a.first-1][a.second] = '*';
        ar[b.first-1][b.second]= '*';
      }else{
        ar[a.first+1][a.second]= '*';
        ar[b.first+1][b.second]= '*';
      }
    }else if(a.second == b.second){
      if(a.second == n-1){
        ar[a.first][a.second-1]= '*';
        ar[b.first][b.second-1]= '*';
      }else{
        ar[a.first][a.second+1]= '*';
        ar[b.first][b.second+1]= '*';
      }
    }else{
      if(a.first == min(a.first,b.first) && a.second == min(a.second,b.second)){
        ar[min(a.first,b.first)][max(a.second,b.second)] = '*';
        ar[max(a.first,b.first)][min(a.second,b.second)] = '*';
      }else{
        ar[min(a.first,b.first)][min(a.second,b.second)] = '*';
        ar[max(a.first,b.first)][max(a.second,b.second)] = '*';
      }
    }
    for(int i = 0 ;i  < n ; i++){
      for(int j = 0 ; j < n ; j++){
        cout << ar[i][j];
      }
      cout << endl;
    }
  }
	return 0;
}