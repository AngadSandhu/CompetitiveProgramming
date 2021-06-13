#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
int grid[66][66];
bool vis[66][66];
int dis[66][66];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int r, c;
int k;
void bfs() {
    queue<int>qx, qy;
    for(int i = 0; i < 64; i++) {
        for(int j = 0; j < 64; j++) {
            if(grid[i][j]) {
                qx.push(i);
                qy.push(j);
                dis[i][j] = 0;
            }
        }
    }

    while(!qx.empty()) {
        int a = qx.front();
        int b = qy.front();
        //cout << a << " " << b << "\n";
        qx.pop();
        qy.pop();
        if(vis[a][b])continue;
        vis[a][b] = 1;
        for(int w = 0; w < 8; w++) {
            int na = a + dx[w];
            int nb = b + dy[w];
            if(na < 0 || nb < 0 || na >= 65 || nb >= 65) continue;
            if(dis[na][nb] == 1000005) {
                dis[na][nb] = dis[a][b] + 1;
                qx.push(na);
                qy.push(nb);
            }
        }
    }

}
int main(){
    
    cin >> r >> c;
    
    cin >> k;
    for(int i = 0; i < 65; i++) {
        for(int j = 0; j < 65; j++) {
            dis[i][j] = 1000005;
        }
    }
    for(int i = 21; i < 21 + r; i++) {
         for(int j = 21; j < 21 + c; j++) {
            char cc;
            cin >> cc;
            if(cc == '.')  grid[i][j] = 0;
            else grid[i][j] = 1;
         }
    }
    bfs();
    int cnt = 0;
    if(k <= 20) {
        for(int i = 0; i < 65; i++) {
            for(int j = 0; j < 65; j++) {
                if(dis[i][j] <= k) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    else {
        int minir = 100, minic = 100;
        int maxir = 0, maxic = 0;
        for(int i = 0; i < 65; i++) {
            for(int j = 0; j < 65; j++) {
                if(dis[i][j] <= 20) {
                    cnt++;
                    minir = min(minir, i);
                    maxir = max(maxir, i);
                    minic = min(minic, j);
                    maxic = max(maxic, j);
                }
            }
        }
        ll a1 = (maxir - minir + 1);
        ll a2 = (maxic - minic + 1);
        ll falta = a1 * a2 - cnt;
        ll res = (a1 + 2 * k - 40) * (a2 + 2*k - 40) - falta;
        cout << res << "\n";
    }
    return 0;
}