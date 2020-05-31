#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 20
pair<int,int> sp[N];
int n,m;
bool visit[N];
string s;
inline void dfs2(int x){
    visit[x] = 1;
    x = s[x]-'a';
    while(!visit[x]){
        visit[x] = 1;
        x = s[x]-'a';
    }
}
unordered_set<string> vis;
int res = INT_MAX;
inline void mn(){
    int c = 0;
    for(int i = 0 ; i < n ; i++){
        if(!visit[i]){ 
            dfs2(i);
            c++;
        }
    }
    res = min(res, n - c);
    for(int i = 0 ; i < n ; i++) visit[i] = 0;
}
inline void dfs1(){
    if(res==0) return;
    vis.insert(s);
    bool flag = 0;
    for(int i = 0 ; i < m ; i++){
        if((s[sp[i].first]==char(sp[i].first+'a')) && (s[sp[i].second]==char(sp[i].second+'a'))) continue;
        flag = 1;
        swap(s[sp[i].first],s[sp[i].second]);
        if(!vis.count(s)) dfs1();
        swap(s[sp[i].first],s[sp[i].second]);
    }
    if(!flag) mn();
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> n >> m;
        s.clear();
        for(int i = 0, x; i < n ; i++) cin >> x, s += char(x-1+'a');
        for(int i = 0 ; i < m ; i++) cin >> sp[i].first >> sp[i].second, sp[i].first--, sp[i].second--;
        dfs1();
        cout << res << endl;
        vis.clear();
        res = INT_MAX;
    }
	return 0;
}