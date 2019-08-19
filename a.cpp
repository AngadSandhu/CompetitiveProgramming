#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ii pair<int,int>
#define N 0
typedef long long ll;
 
using namespace std;
int n;
vector<int> bits [64]
ll a[100005];
bool b[100005][64];
vector<int>adj[
void dfs(ll d, int ){

}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for(int i = 0 ; i < 64 ; i++){
		for(int j = 0 ; j < n ; j++){
			if((a[j]>>i)&1){
				bits[i].push_back(j);
				a[j][i] = 1;
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 64 ; j++){
			if
		}
	}
	return 0;
}
