#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 5000005

pair<int,int> pairSum[N];

int main(){
	FIO;
  for(int i = 0 ; i < N ; i++) pairSum[i] = {-1,-1};
	int n; cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  for(int i = 0 ; i < n ; i++){
    for(int j = i+1 ; j < n ; j++){
      int sum = a[i] + a[j];
      if(pairSum[sum].first == -1) pairSum[sum] = {i,j};
      else if((pairSum[sum].first != i && pairSum[sum].second != j) && 
      (pairSum[sum].first != j && pairSum[sum].second != i)){
        cout << "YES" << endl;
        cout << pairSum[sum].first + 1 << " " << pairSum[sum].second + 1 << " " << 
        i+1 << " " << j+1 << endl;
        return 0;
      } 
    }
  }
  cout << "NO" << endl;
	return 0;
}