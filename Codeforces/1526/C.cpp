#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n; cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  multiset<int> s;
  ll sum = 0;
  for(int i = 0 ; i < n ; i++){
    sum += a[i];
    s.insert(a[i]);
    if(sum < 0){
      sum -= *s.begin();
      s.erase(s.begin());
    }
  }
  cout << s.size() << endl;
	return 0;
}