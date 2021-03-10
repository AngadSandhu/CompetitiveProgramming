#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

bool isValid(string s){
  stack<char> q;
  for(int i = 0; i < s.size() ; i++){
    if(!q.empty() && (q.top() == '(' && s[i] == ')')) q.pop();
    else q.push(s[i]);
  }
  return q.empty();
}
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    string s; cin >> s;
    bool ans = 0;
    for(int i = 0 ; i < (1<<3) ; i++){
      string tran = s;
      for(int j = 0 ; j < s.size() ; j++){
        int p = (tran[j]-'A');
        tran[j] = ( ((i>>p)&1) ? '(' : ')');
        if(isValid(tran)) ans = 1;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
	return 0;
}