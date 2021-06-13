#include<bits/stdc++.h>
using namespace std;
#define N 51
int n,m,k;
string a[N];
struct data{
    int r,c,vr,vc,k;
};
int dist[7][N][N][2*N][2*N];
bool valid(int r, int c){
    if(r < 0 || r >= n) return 0;
    if(c < 0 || c >= m) return 0;
    if(a[r][c] == '#') return 0;
    return 1;
}
int main(){
    int r,c,finr,finc;
    cin >> n >> m >> k;
    queue<data> Q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == '0') r = i, c = j;
            if(a[i][j]-'0' == k+1) finr = i, finc = j;
        }
    }
    memset(dist,-1,sizeof dist);
    dist[0][r][c][N][N] = 0;
    bool flag = 1;
    Q.push({r,c,0,0,0});
    while(!Q.empty() && flag){
        data cur = Q.front(); Q.pop();
        //cout << cur.r << " " << cur.c << " " << cur.vr << " " << cur.vc << endl;
        for(int dr = -1; dr <= 1 && flag; dr++){
            for(int dc = -1; dc <= 1 && flag; dc++){
                int nvr = cur.vr+dr, nvc = cur.vc+dc;
                int nr = cur.r+nvr, nc = cur.c+nvc;
                if(!valid(nr,nc)) continue;
                int nk = cur.k + (a[nr][nc]-'0' == cur.k+1);
                if(dist[nk][nr][nc][N+nvr][N+nvc] == -1){
                    dist[nk][nr][nc][N+nvr][N+nvc] = dist[cur.k][cur.r][cur.c][N+cur.vr][N+cur.vc] + 1;
                    if(nk == k+1 && nr == finr && nc == finc && nvr == 0 && nvc == 0) flag = 0;
                    Q.push({nr,nc,nvr,nvc,nk});
                }
            }
        }
    }
    if(flag) cout << "impossible" << endl;
    else cout << dist[k+1][finr][finc][N][N] << endl;
    
    return 0;
}