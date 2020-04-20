#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define N 5005
#define M 100000
int const mod = 1e9;
double prob[N][N];

int main(){
	int t,caso = 0; cin >> t;
    while(t--){
        int w,h,l,u,r,d; cin >> w >> h >> l >> u >> r >> d;
        w--,h--,l--,u--,r--,d--;
        double res = 0;
        if(w < N && h < N){
            prob[0][0] = 1.0;
            for(int i = 1 ; i <= w ; i++) prob[0][i] = 0.5 * prob[0][i-1];
            for(int i = 1 ; i <= h ; i++) prob[i][0] = 0.5 * prob[i-1][0];
            for(int i = 1 ; i <= h ; i++){
                for(int j = 1 ; j <= w ; j++){
                    prob[i][j] = (i==h?1.0:0.5) * prob[i-1][j] + (j==w?1.0:0.5) * prob[i][j-1];
                }
            }
            //for(int i = 0 ; i<= h ;i++){ for(int j = 0 ; j <=w ; j++) cout << prob[i][j] << " "; cout << endl; }
            res += prob[u][l];
            for(int i = u+1 ; i <= d ; i++){
                res += prob[i][l] - prob[i-1][l]*(l==w?1:0.5);
            }
            for(int i = l+1 ; i <= r ; i++){
                res += prob[u][i] - prob[u][i-1]*(u==h?1:0.5);
            }
        }else{
            for(int i = u+1 ; i <= d ; i++){
                if(i < N && l < N) res += prob[i][l];
                else if(i > M - N && l > M - N) res =+ prob[M-i][M-l];
            }
            for(int i = l+1 ; i <= r ; i++){
                if(i < N && u < N) res += prob[u][i];
                else if(i > M-N && u > M-N) res += prob[M-u][M-i];
            }
        }
        printf("Case #%d: %.5f\n",++caso,res);
    }
	return 0;
}