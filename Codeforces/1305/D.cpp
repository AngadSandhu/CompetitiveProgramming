#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
int ask(int u,int v){
    cout << "? " << u << " " << v << endl;
    int ans; cin >> ans;
    return ans;
}
int n;
set<int> adj[N];
int main(){
	FIO;
    cin >> n;
    for(int i = 0 ; i < n-1 ; i ++){
        int x,y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int> leaf;
    for(int i = 1 ; i <= n ; i ++){
        if(adj[i].size()==1) leaf.pb(i);
    }
    while(leaf.size() >= 2){
        int x = leaf.back(), y = leaf[leaf.size()-2];
        int r = ask(x,y);
        if(r == x || r == y){
            cout <<"! "<< r << endl;
            return 0;
        }
        leaf.pop_back();
        leaf.pop_back();
        int px = *adj[x].begin(), py = *adj[y].begin();
        adj[px].erase(x);
        if(adj[px].size()==1) leaf.pb(px);
        adj[py].erase(y);
        if(adj[py].size()==1) leaf.pb(py);
    }
    cout << "! " << leaf.back() << endl;
	return 0;
}