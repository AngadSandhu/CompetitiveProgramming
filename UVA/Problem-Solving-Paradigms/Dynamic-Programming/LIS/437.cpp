#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
struct Block{
  int x,y,z;
  Block(int _x, int _y, int _z): x(_x),y(_y), z(_z){};
};
vector<Block> ar;
int n;
int memo[N];
int dp(int p){
  int &ret = memo[p];
  if(ret != -1) return ret;
  int ans = 0;
  Block  B = ar[p];
  int x = B.x, y = B.y, z = B.z;
  for(int i = p+1 ; i < n; i++)
    if(ar[i].x > x && ar[i].y > y) ans = max(ans, ar[i].z + dp(i));
  return ret = ans;
}
bool comp(Block &b1, Block &b2){
  if(b1.x == b2.x){
    return make_pair(b1.y,b1.z) < make_pair(b2.y,b2.z);
  }else{
    return b1.x < b2.x;
  }
}
int main(){
	FIO;
  int caso = 0;
  while(cin >> n, n > 0){
    memset(memo,-1,sizeof memo);
    for(int i = 1 ; i <= n ; i++){
      int x[3]; cin >> x[0] >> x[1] >> x[2];
      sort(x,x+3);
      do{
        ar.pb(Block(x[0],x[1],x[2]));
      }while(next_permutation(x,x+3));
    }
    ar.pb(Block(-1,-1,-1));
    sort(ar.begin(),ar.end(),comp);
    n = ar.size();
    // for(int i = 0 ; i< ar.size() ; i++) cout << ar[i].x << " " << ar[i].y << " " << ar[i].z << endl;
    
    printf("Case %d: maximum height = %d\n",++caso,dp(0));
    ar.clear();
  }
	return 0;
}