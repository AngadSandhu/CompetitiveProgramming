#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
char a[55][55], ar1[55][55], ar2[55][55];
int n,m;
bool check1(){
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(a[i][j] != ar1[i][j] && a[i][j] != '.') return false;
      }
    }
    return true;
}
bool check2(){
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if(a[i][j] != ar2[i][j] && a[i][j] != '.') return false;
      }
    }
    return true;
}
void print1(){
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cout << ar1[i][j];
      }
      cout << endl;
    }
}
void print2(){
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cout << ar2[i][j];
      }
      cout << endl;
    }
}
int main(){
	FIO;
  int t; cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cin >> a[i][j];
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if((i+j)%2){
          ar1[i][j] = 'R';
        }else{
          ar1[i][j] = 'W';
        }
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        if((i+j)%2){
          ar2[i][j] = 'W';
        }else{
          ar2[i][j] = 'R';
        }
      }
    }
    if(check1()){
      cout << "YES" << endl;
      print1();
    }else if(check2()){
      cout << "YES" << endl;
      print2();
    }else{
      cout << "NO" << endl;
    }
  }	
	return 0;
}