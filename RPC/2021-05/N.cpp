#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n; cin >> n;
  string s = "", t = ""; cin >> s;
  for(int i = 0 ; i < n ; i++){
    t += to_string(i+1);
    if(s.substr(0,t.size()) != t){
      cout << i+1 << endl;
      break;
    }
  }
	return 0;
}