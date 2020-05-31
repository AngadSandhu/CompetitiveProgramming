#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
int n,m;
bool a[N][N];
bool visit[N][N];
int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};
void dfs(int r,int c){
    visit[r][c] = 1;
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(visit[nr][nc]) continue;
        if(!a[nr][nc]) continue;
        dfs(nr,nc);
    }
}
int main(){
	FIO;
        cin >> n >> m;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                char x; cin >> x;
                a[i][j] = (x=='#');
            }
        }
        bool posi = 1, whiter = 0,whitec = 0;
        for(int i = 0 ; i < n ; i++){
            int first = -1;
            for(int j = 0 ; j < m ; j++){
                if(a[i][j]){
                    first = j;
                    break;
                }
            }
            if(first==-1) whiter = 1;
            bool flag = 0;
            for(int j = first; j < m ; j++){
                if(!a[i][j]) flag = 1;
                if(a[i][j] && flag) posi = 0;
            }
        }
        for(int i = 0 ; i < m ; i++){
            int first = -1;
            for(int j = 0 ; j < n ; j++){
                if(a[j][i]){
                    first = j;
                    break;
                }
            }
            if(first==-1) whitec= 1;
            bool flag = 0;
            for(int j = first; j < n ; j++){
                if(!a[j][i]) flag = 1;
                if(a[j][i] && flag) posi = 0;
            }
        }
        posi &= !(whiter^whitec);
        if(posi){
            int res = 0;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(a[i][j] && !visit[i][j]) res++, dfs(i,j);
                }
            }
            cout << res << endl;
        }else{
            cout << -1 << endl;
        }
	return 0;
}