#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 2005
string aux[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int num[10], ar[N],n,k;
int dp[N][N], recon[N][N];
int used(int x,int to){
    int ret = 0;
    for(int i = 0 ; i < 7 ; i++){
        if(!(num[to]&(1<<i)) && (x&(1<<i))) return -1;
        if((num[to]&(1<<i)) && !(x&(1<<i))) ret++;
    }
    return ret;
}
int f(int pos,int left){
    if(left < 0) return 0;
    if(pos == n && left==0) return 1;
    if(pos == n) return 0;
    if(dp[pos][left] != -1) return dp[pos][left];
    for(int i = 9 ; i >= 0 ; i--){
        if(used(ar[pos],i)!=-1 && f(pos+1,left-used(ar[pos],i))){
            recon[pos][left] = i;
            return dp[pos][left] = 1;
        }
    }
    return dp[pos][left] = 0;
}
int main(){
	FIO;
	for(int i = 0; i < 10 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            if(aux[i][j]=='1') num[i] += (1<<j);
        }
    }
    memset(dp,-1,sizeof dp);
        cin >> n >> k;
        for(int i = 0 ; i < n ; i++){
            string s; cin >> s;
            for(int j = 0 ; j < 7 ; j++){
                if(s[j]=='1') ar[i] += (1<<j);
            }
        }
        if(f(0,k) == 0){
            cout << -1 << endl;
        }else{
            int x = 0, y = k;
            string res = "";
            while(x < n){
                res += char(recon[x][y] + '0');
                y -= used(ar[x],recon[x][y]);
                x++;
            }
            cout << res << endl;
        }
	return 0;
}