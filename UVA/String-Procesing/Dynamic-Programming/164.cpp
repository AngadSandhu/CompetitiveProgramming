#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int dp[N][N], go[N][N];
string s,t;
void print(){
  string ans = "";
  int i = 0, j = 0, currPos = 1;
  while(i < s.size() || j < t.size()){
    if(go[i][j] == 0){
      i++; j++;
      currPos++;
    }else if(go[i][j] == 1){
      printf("D%c%02d",s[i],currPos);
      i++;
    }else if(go[i][j] == 2){
      printf("I%c%02d",t[j],currPos);
      j++;
      currPos++;
    }else{
      printf("C%c%02d",t[j],currPos);
      i++; j++;
      currPos++;
    }
  }
  printf("E\n");
}
int main(){
  while(cin >> s){
    if(s == "#") break;
    cin >> t;
    dp[s.size()][t.size()] = 0;
    for(int i = s.size()-1, j = t.size() ; i >= 0 ; i--){
      go[i][j] = 1;
      dp[i][j] = 1 + dp[i+1][j];
    }
    for(int j = t.size() -1, i = s.size() ; j >= 0 ; j--){
      go[i][j] = 2;
      dp[i][j] = 1 + dp[i][j+1];
    }
    for(int i = s.size()-1 ; i >= 0 ; i--){
      for(int j = t.size()-1; j >= 0 ; j--){
        dp[i][j] = INT_MAX;
        if(s[i] == t[j]){
          dp[i][j] = dp[i+1][j+1];
          go[i][j] = 0;
        }else{
          dp[i][j] = min(dp[i][j],1 + dp[i+1][j]);
          dp[i][j] = min(dp[i][j],1 + dp[i][j+1]);
          dp[i][j] = min(dp[i][j],1 + dp[i+1][j+1]);
          if(dp[i][j] == 1 + dp[i+1][j]){
            go[i][j] = 1;
          }else if(dp[i][j] == 1 + dp[i][j+1]){
            go[i][j] = 2;
          }else{
            go[i][j] = 3;
          }
        }
      }
    }
    print();
  }
	return 0;
}