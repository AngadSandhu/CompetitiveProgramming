#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
ll BIT[20][N];
int n,k;
void add(int id,int pos,ll val){
  for(int i = pos ; i < N ; i+=i&-i) BIT[id][i] += val;
}
ll query(int id, int pos){
  ll ret = 0;
  for(int i = pos ; i > 0 ; i-=i&-i) ret += BIT[id][i];
  return ret;
}
int ar[N];
int main(){
	FIO;
  cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
    cin >> ar[i];
  }
  for(int i = 0 ; i < n ; i++){
    add(1,ar[i],1);
    for(int j = 2 ; j <= k+1 ; j++){
      add(j,ar[i],query(j-1,ar[i]-1));
    }
  }
  cout << query(k+1,N) << endl;
	return 0;
}