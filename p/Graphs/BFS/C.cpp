#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 50
int n1,n2;
map<pair<string,string>,int> d;
string s1[N],s2[N];
void bfs(){
  queue<pair<string,string>> q;
  for(int i = 0 ; i < n1 ; i++) q.push({s1[i],""}), d[{s1[i],""}] = 1;
  for(int i = 0 ; i < n2 ; i++) q.push({"" ,s2[i]}), d[{"",s2[i]}] = 1;
  
  while(!q.empty()){
    auto u = q.front();
    q.pop();
    if(u.first.empty()){
      for(int i = 0 ; i < n1 ; i++){
        pair<string,string> s;
        bool found = 0;
        if(u.second.size() < s1[i].size()){
          if(u.second == s1[i].substr(0,u.second.size())){
            s = {s1[i].substr(u.second.size()),""};
            found = 1;
            //cout << u.first << ":" << u.second <<" " <<  i << endl;
          }
        }else{
          if(u.second.substr(0,s1[i].size()) == s1[i]){
            s = {"",u.second.substr(s1[i].size())};
            found = 1;
          }
        }
        if(!found) continue;
        if(d.find(s) == d.end()){
          // cout << u.first << ":" << u.second << " + " << s1[i] << 
          // " -> " << s.first << ":" << s.second << endl;
          d[s] = 1;
          q.push(s);
        }
      }
    }else{
      for(int i = 0 ; i < n2 ; i++){
        pair<string,string> s;
        bool found = 0;
        if(u.first.size() < s2[i].size()){
          if(u.first == s2[i].substr(0,u.first.size())){
            s = {"",s2[i].substr(u.first.size())};
            found = 1;
            //cout << u.first << ":" << u.second <<" " <<  i << endl;
          }
        }else{
          if(u.first.substr(0,s2[i].size()) == s2[i]){
            s = {u.first.substr(s2[i].size()),""};
            found = 1;
          }
        }
        if(!found) continue;
        if(d.find(s) == d.end()){
          // cout << u.first << ":" << u.second << " - " << s2[i] << 
          // " -> " << s.first << ":" << s.second << endl;
          d[s] = 1;
          q.push(s);
        }
      }
    }
  }
  
}
int main(){
	FIO;
	
  while(cin >> n1 >> n2){
    d.clear();
    for(int i = 0 ; i < n1 ; i++) cin >> s1[i];
    for(int i = 0 ; i < n2 ; i++) cin >> s2[i];
    bfs();
    if(d.find({"",""}) != d.end()) cout << "S" << endl;
    else cout << "N" << endl;
    
  }

	return 0;
}