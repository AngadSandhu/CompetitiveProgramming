#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1100005
#define LOGN 25
int BIT[N];
int n,k;
void update(int pos, int val){
  for(int i=pos ; i < N ; i+=i&-i) BIT[i] += val;
}
int query(int pos){
  int ret = 0;
  for(int i=pos; i > 0 ; i-=i&-i) ret += BIT[i];
  return ret;
}
int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	for(int i=LOGN; i>=0; i--)
	{
    int x = pos + (1 << i);
		if(x < N and sum + BIT[x] < v)
		{
			sum += BIT[x];
			pos += (1 << i);
		}
	}

	return pos + 1;
}
int main(){
	FIO;
	cin >> n >> k;
  for(int i = 1 ; i <= n ; i++) update(i,1);
  int pos = k;
  int order = 1;
  int ans = 0;
  while(true){
    // Reduce curr position
    update(pos,-1);
    ans ^= abs(pos-order++);
    if(order == n+1) break;
    // Get next position
    int T = query(n);
    int kth = (query(pos) + k)%T==0? T : (query(pos) + k)%T;
    pos = bit_search(kth);
  }
  cout << ans << endl;
	return 0;
}