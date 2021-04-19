#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int dp[N][N];
int main()
{
  FIO;
  int n, k;
  while (cin >> n >> k, n > 0)
  {
    dp[0][0] = 1;
    for (int j = 1; j <= k; j++){
      for (int i = 1; i < n; i++){
        for (int w = 1; w <= i; w++)
        {
          dp[i][j] += dp[i - w][j - 1] + dp[i-w][j];
        }
      }
    }
    cout << dp[n][k] << endl;
  }
  return 0;
}