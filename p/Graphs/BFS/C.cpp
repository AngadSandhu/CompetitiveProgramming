#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int n1,n2;
map<pair<string,bool>,int> d;
string s1[N],s2[N];
void bfs(){
  queue<pair<string,bool>> q;
  for(int i = 0 ; i < n1 ; i++) q.push({s1[i],1}), d[{s1[i],1}] = 1;
  for(int i = 0 ; i < n2 ; i++) q.push({s2[i],0}), d[{s2[i],0}] = 1;
  
  while(!q.empty()){
    auto u = q.front();
    q.pop();
    if(u.second){
      for(int i = 0 ; i < n2 ; i++){
        if(u.first
      }
    }
  }
  
}
int main(){
	FIO;
	
  while(cin >> n1 >> n2){
    for(int i = 0 ; i < n1 ; i++) cin >> s1[i];
    for(int i = 0 ; i < n2 ; i++) cin >> s2[i];

    
  }

	return 0;
}