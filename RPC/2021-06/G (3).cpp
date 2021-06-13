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
const int N = 250006;
int ufila[N];
int udiag1[N];
int udiag2[N];
int cnt[N];
int tipo[N];
int col[N];
vector<vector<int>>v;
int h, w, k;
int awa (int x, int y) {
    return x * w + y;
}
int findfila(int x) {
    if(ufila[x] < 0) return x;
    return ufila[x] = findfila(ufila[x]);
}
int finddiag1(int x) {
    if(udiag1[x] < 0) return x;
    return udiag1[x] = finddiag1(udiag1[x]);
}
int finddiag2(int x) {
    if(udiag2[x] < 0) return x;
    return udiag2[x] = finddiag2(udiag2[x]);
}
void joinfila(int u, int v) {
    u = findfila(u);
    v = findfila(v);
    if(u == v) return;
    if(ufila[u] > ufila[v]) swap(u, v);
    ufila[u] += ufila[v];
    ufila[v] = u;
}
void joindiag1(int u, int v) {
    u = finddiag1(u);
    v = finddiag1(v);
    if(u == v) return;
    if(udiag1[u] > udiag1[v]) swap(u, v);
    udiag1[u] += udiag1[v];
    udiag1[v] = u;
}
void joindiag2(int u, int v) {
    u = finddiag2(u);
    v = finddiag2(v);
    if(u == v) return;
    if(udiag2[u] > udiag2[v]) swap(u, v);
    udiag2[u] += udiag2[v];
    udiag2[v] = u;
}
bool can(int f, int c, int color) {
    v[f][c] = color; 
    
    if(tipo[c] == color) cnt[c]++;
    else {
        tipo[c] = color;
        cnt[c] = 1;
    }
    if(cnt[c] >= k) return 1;
    if(c != 0 && v[f][c - 1] == color) {
        joinfila(f*w + c, f*w + c - 1);
    }
    if(c != w - 1 && v[f][c + 1] == color) {
        
        joinfila(f*w + c, f*w + c + 1);
    }
    // diag 1
    if(c != w - 1 && f != h - 1 && v[f + 1][c + 1] == color) {
        joindiag1(awa(f, c), awa(f + 1, c + 1));
    }
    if(c != 0 && f != 0 && v[f - 1][c - 1] == color) {
        joindiag1(awa(f, c), awa(f - 1, c - 1));
    }
    // diag 2
    if(c != w - 1 && f != 0 && v[f - 1][c + 1] == color) {
        joindiag2(awa(f, c), awa(f - 1, c + 1));
    }
    if(c != 0 && f != h - 1 && v[f + 1][c - 1] == color) {
        joindiag2(awa(f, c), awa(f + 1, c - 1));
    }
    if(-ufila[findfila(awa(f, c))] >= k) return 1;
    if(-udiag1[finddiag1(awa(f, c))] >= k) return 1;
    if(-udiag2[finddiag2(awa(f, c))] >= k) return 1;
    
    return 0;
}
int main(){
    
    cin >> h >> w >> k;
    memset(ufila, -1, sizeof(ufila));
    memset(udiag1, -1, sizeof(udiag1));
    memset(udiag2, -1, sizeof(udiag2));
    // 0 vacio
    // 1 A
    // 2 B
    for(int i = 0; i < h; i++) {
        vi v2(w, 0);
        v.pb(v2);
    }
    
    int ab = 1;
    int winner = 0;
    int turno = -1;
    
    for(int i = 0, x; i < h*w; i++) {
       // cout << i  << " ";
        cin >> x;
        x--;
       // cout << i << " " << col[x] << " " << x << " " << "\n";
        if(can(col[x], x, ab)) {
            winner = ab;
            turno = i + 1;
            break;
        }
        col[x]++;
        ab = 3 - ab;
    }
    if(turno == -1) cout << "D\n";
    else {
        cout << char('A' + ab - 1) << " " << turno << "\n";
    }
    return 0;
}