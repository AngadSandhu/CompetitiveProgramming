#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int dp[N];
int freq[N][26];
int f(int pos){
    if(dp[pos] != -1) return dp[pos];

}
int main(){
	FIO;
    string s; cin >> s;
    for(int i = s.size()-1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 26; j++){
            freq[i][j] = freq[i+1][j];
        }
        freq[i][s[i]-'a']++;
    }
	return 0;
}