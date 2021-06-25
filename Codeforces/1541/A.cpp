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
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) a[i] = i+1;
    if(n%2){
      for(int i = 0 ; i < n-3 ; i+=2){
        cout << a[i+1] << " " << a[i] << " ";
      }
      cout << a[n-1] << " " << a[n-3] <<  " " << a[n-2] << endl;
    }else{
      for(int i = 0 ; i < n ; i+=2){
        cout << a[i+1] << " " << a[i] << " ";
      }
    }
    cout << endl;
  }
	return 0;
}