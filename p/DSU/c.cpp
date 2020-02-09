#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[2][505][505];
char ar[505][505];
int n,m;
bool valid(int r1,int r2,int sum){
    int c1 = sum - r1, c2 = n+m-r2-2-sum;
    if(c1<0 || c1>=m || c2<0 || c2>=m) return 0;
    if(r2 < r1 || c2 < c1) return 0;
    if(ar[r1][c1] != ar[r2][c2]) return 0;
    return 1;
}
int main(){
    memset(dp,0,sizeof dp);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> ar[i][j];
        }
    }
    dp[0][0][n-1] = (ar[0][0] == ar[n-1][m-1]);

    for(int sum = 1 ; sum <= (n+m-2)/2 ; sum++){
        bool ant = (sum-1)%2;
        for(int r1 = 0 ; r1 < n ; r1++){
            for(int r2 = 0 ; r2 < n ; r2++){
                int ret = 0,c1 = sum-r1, c2 = n+m-r2-2-sum;
                if(!valid(r1,r2,sum)) continue;
                if(r1>0 && r2<n-1) ret = (ret + dp[ant][r1-1][r2+1])%mod;
                if(r1>0 && c2<m-1) ret = (ret + dp[ant][r1-1][r2])%mod;
                if(c1>0 && r2<n-1) ret = (ret + dp[ant][r1][r2+1])%mod;
                if(c1>0 && c2<m-1) ret = (ret + dp[ant][r1][r2])%mod;
                dp[sum%2][r1][r2] = ret;
            }
        }
        memset(dp[ant],0,sizeof dp[ant]);
    }
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            res = (res + dp[((n+m-2)/2)%2][i][j])%mod;
        }
    }
    cout << res << endl;
    return 0;
}