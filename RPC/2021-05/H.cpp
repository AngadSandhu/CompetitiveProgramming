#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	string s; cin >> s;
  string t = s;
  sort(t.begin(),t.end());
  t.resize(unique(t.begin(),t.end())-t.begin());
  if(t.size() == s.size()) cout << 1 << endl;
  else cout << 0 << endl;
	return 0;
}