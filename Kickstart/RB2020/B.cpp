#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define N 305
#define M 100000
int w,h,l,u,d,r;
double memo[N][N];
bool visit[N][N];
double dp(int f,int c){
    if(visit[f][c]) return memo[f][c];
    if((f>=u && f<=d)&&(c<=r&&c>=l)) return 0;
    if(f==h && c==w) return 1;
    visit[f][c] = 1;
    return memo[f][c] = (f==h?0:1)*dp(min(f,f+1),c) + (c==w?0:1)*dp(f,min(c,c+1));
}
int main(){
    int t, caso = 0;
    cin >> t;
    while(t--){
        cin >> w >> h >> l >> u >> d >> r;
        printf("Case #%d: %.5f\n",++caso,dp(1,1));
        memset(visit,0,sizeof visit);
    }
    return 0;
}