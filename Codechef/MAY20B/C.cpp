#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
struct trip{
    int a,b,c;
    trip(){};
    trip(int a,int b,int c): a(a), b(b), c(c) {};
};
bool visit[N];
int p[N];
int n,k;
vector<vector<int>> ciclo,pares;
vector<trip> ans;
vector<int> dfs(int s){
    vector<int> ret;
    ret.pb(s);
    visit[s] = 1;
    s = p[s];
    while(!visit[s]){
        ret.pb(s);
        visit[s] = 1;
        s = p[s];
    }
    return ret;
}
vector<int> join(){
    vector<int> a = pares.back(); pares.pop_back();
    vector<int> b = pares.back(); pares.pop_back();
    ans.pb({ a[a.size()-2],a.back(), b.back()});
    vector<int> v;
    for(int i = 0 ; i < (int)a.size()-1 ; i++) v.pb(a[i]);
    for(int i = 0 ; i < (int)b.size() ; i++) v.pb(b[i]);
    return v;
}
void reducir(int id){
    int m;
    while(ciclo[id].size() >= 3){
        m = ciclo[id].size();
        ans.pb(trip(ciclo[id][m-3],ciclo[id][m-2],ciclo[id][m-1]));
        ciclo[id].pop_back();
        ciclo[id].pop_back();
    }
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ans.clear();
        pares.clear();
        ciclo.clear();
        for(int i = 1 ; i <= n ; i++) visit[i] = 0;
        cin >> n >> k;
        for(int i = 1 ; i <= n ; i++) cin >> p[i];
        for(int i = 1 ; i <= n ; i++){
            if(!visit[i]){
                vector<int> v = dfs(i);
                if(v.size()%2==0) pares.pb(v);
                else ciclo.pb(v); 
            }
        }
        if(pares.size()%2){
            cout << -1 << endl;
            continue;
        }
        while(!pares.empty()){
            ciclo.pb(join());
        }
        for(int i = 0 ; i < (int)ciclo.size() ; i++){
            reducir(i);
        }
        if((int)ans.size() > k){
            cout << -1 << endl;
        }else{
            cout << ans.size() << endl;
            for(auto v : ans){
                cout << v.a << " " << v.b << " " << v.c << endl;
            }
        }
    }
	return 0;
}