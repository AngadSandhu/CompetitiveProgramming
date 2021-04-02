#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 50
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(j==d.size()) d.pb(a[i]);
        else d[j] = a[i];
    }
    return d.size();
}
int rnk[N], toMap[N];
int main(){
	FIO;
  int n; cin >> n;
  while(true){
    for(int i = 0 ; i < n ; i++){ 
      int x; 
      cin >> x; 
      rnk[--x] = i;
    }
    for(int i = 0 ; i < n ; i++) toMap[rnk[i]] = i;
    cin.ignore();
    while(true){
      vector<int> v;
      string s;
      getline(cin,s);
      stringstream in(s);
      int x; 
      while(in >> x){
        v.pb(x);
      }
      if(v.size() == 1){
        n = v[0];
        break;
      }else if(v.size()==0){
        return 0;
      }else{
        vector<int> x(n);
        for(int i = 0 ; i < n ; i++) x[--v[i]] = i;
        for(int i = 0 ; i < n ; i++) x[i] = toMap[x[i]];
        // for(int i = 0 ; i < v.size() ; i++) cout << v[i] << " "; cout << endl;
        cout << lis(x) << endl;
      }
    }

  }
	return 0;
}