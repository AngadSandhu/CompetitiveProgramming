#include <bits/stdc++.h>
using namespace std;

int dc[3] = { 1, 1, 1};
int dr[3] = {-1, 0, 1};
int r, c, p;
int matrix[505][505];
int mpasses[505][505];
long long d[505][505];

long long memo[505][505][15];

long long dp(int si, int sj, int k){
    long long ans = INT_MAX;
    if(k < 0) return INT_MAX;
    
    if(si == -1){
        for(int i = 0 ; i < r ; i ++){
            if(matrix[i][0] != -1) ans = min(ans, dp(i, 0, k) + matrix[i][0]);
        }
        return ans;
    }

    if(memo[si][sj][k] != -1) return memo[si][sj][k];


    if(sj == c-1){
        if(k == 0) return 0;
        else return INT_MAX;
    }
    else{
        for(int i = 0 ; i < 3 ; i ++){
            int ni = si + dr[i];
            int nj = sj + dc[i];

            if(ni >= 0 && ni < r && nj >= 0 && nj < c && matrix[ni][nj] != -1){
                ans = min(ans, dp(ni, nj, k - mpasses[ni][nj]) + matrix[ni][nj]);
            }
        }
    }


    return memo[si][sj][k] = ans;
}



int main(){
    for(int i = 0 ;  i < 500 ; i++)
    for(int k = 0 ;  k < 500 ; k++)
        for(int j = 0; j < 12; j++)
            memo[i][k][j] = -1;

    cin >> r >> c >> p;
    for(int i = 0  ; i < r ; i++) 
        for(int j = 0 ; j < c ; j++)
            cin >> matrix[i][j], mpasses[i][j] = 0;

    for(int i = 1  ; i < r-1 ; i++) 
        for(int j = 1 ; j < c-1; j++){
            if( matrix[i][j] != -1)
            if( matrix[i][j] < matrix[i-1][j] && matrix[i-1][j] != -1)
            if( matrix[i][j] < matrix[i+1][j] && matrix[i+1][j] != -1)
            if( matrix[i][j] > matrix[i][j+1] && matrix[i][j+1] != -1)
            if( matrix[i][j] > matrix[i][j-1] && matrix[i][j-1] != -1)
                mpasses[i][j] = 1;
        }

    long long ans = dp(-1, 0, p);
    if(ans < INT_MAX) cout << ans << endl; 
    else cout << "impossible" << endl;
    return 0;

}
