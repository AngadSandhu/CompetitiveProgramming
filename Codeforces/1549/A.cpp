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
    if(n%2==0){
      cout << "4 2 \n";
    }else{
      cout << (n-1)/2 << " " << n-1 << endl;
    }
  }
	return 0;
}