#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

vector<int> z_function(vector<pair<char,int>> s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && (s[z[i]] == s[i + z[i]] || (s[z[i]].first == '?' &&  s[i + z[i]].first != '#') || (s[i + z[i]].first == '?' && s[z[i]].first != '#')))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
// vector<int> z_function(string s) {
//     int n = (int) s.length();
//     vector<int> z(n);
//     for (int i = 1, l = 0, r = 0; i < n; ++i) {
//         if (i <= r)
//             z[i] = min (r - i + 1, z[i - l]);
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]])
//             ++z[i];
//         if (i + z[i] - 1 > r)
//             l = i, r = i + z[i] - 1;
//     }
//     return z;
// }
int b[N];
int notNull = 0,maxSuff = 0;
vector<pair<char,int>> text,patron;
void process(){
  b[0] = -1;
  for(int i = 1,j = -1,last = 0 ; i <= patron.size() ; i++){
    if(patron[i-1].first == '?') continue;
    while(j != -1 && patron[j + i - last - 1] != patron[i-1]) j = b[j];
    b[i] = ++j;
    last = i;
    notNull++;
    maxSuff = patron.size()-i;
  }
}
int search(){
  int ans = 0;
  for(int i = 0, j = 0, last = 0; i < text.size() ; i++){
    while(j != -1 && patron[j + i - last - 1] != text[i] && text[i].first != '?' && patron[j + i - last - 1].first != '?') j = b[j];
    ++j;
    if(j == notNull){
      if(i + maxSuff < text.size()) ans++;
      j = b[j]; 
    }
    last = i;
  }
  return ans;
}
int main(){
	FIO;
	int n,m; cin >> n >> m;
  
  for(int i = 0 ; i < n ;i++){
    char c; cin >> c;
    if(c=='?') text.pb({c,-1});
    else{
      int x; cin >> x;
      text.pb({c,x});
    }
  }
  for(int i = 0 ; i < m ;i++){
    char c; cin >> c;
    if(c=='?') patron.pb({c,-1});
    else{
      int x; cin >> x;
      patron.pb({c,x});
    }
  }
  vector<int> z = z_function(patron);
  int ans = 0;
  for(int i = 0; i < z.size() ; i++){
    cout << z[i] << endl;
    if(z[i] >= t.size()) ans++;
  }
  cout << ans << endl;
	return 0;
}