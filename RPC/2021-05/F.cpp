#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int n,k; cin >> n >> k;
  vector<int> r(k);
  int sum = 0;
  for(int &i: r) cin >> i, sum += i;
  double mini = (sum - 3*(n-k))/(1.0*n), maxi = (sum + 3*(n-k))/(1.0*n);
  printf("%.4f %.4f\n",mini,maxi);
	return 0;
}