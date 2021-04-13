#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 6005
vector<pair<int,int>> turtle;
int n;

int main(){
	FIO;
  int aux1, aux2;
	while(cin >> aux1 >> aux2) turtle.pb({aux2,aux1});
  n = turtle.size();
  sort(turtle.begin(),turtle.end());
  vector<int> dp;
  dp.pb(turtle[0].second);
  for(int i = 1 ; i < n ; i++){
    for(int j = dp.size()-1 ; j >= 0 ; j--){
      if(turtle[i].first >= dp[j] + turtle[i].second && 
          ((j==dp.size()-1) || (dp[j+1] > dp[j] + turtle[i].second))){
        if(j==dp.size()-1) dp.pb(dp.back()+turtle[i].second);
        else dp[j+1] = dp[j] + turtle[i].second;
      }
    }
  }
  cout << dp.size() << endl;
	return 0;
}