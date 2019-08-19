#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ii pair<int,int>
#define N 0
typedef long long ll;
 
using namespace std;
int n,m;
int a[205],b[205];
bool fa[205],fb[205];
 
void solve(){
	for(int i = 0 ; i < n ;i++){
		for(int j= 0 ; j < m ; j ++){
			if(fa[a[i]+b[j]]==0 && fb[a[i]+b[j]]==0){ cout << a[i] << " "<<	 b[j] << endl; return; }
		}
	}
}
int main(){
	
	cin >> n;
	for(int i = 0 ; i< n ;i++){cin >> a[i]; fa[a[i]] = 1;}
	cin >> m;
	for(int i = 0 ; i< m ;i++){cin >> b[i]; fb[b[i]] = 1;}
	solve();
	
	return 0;
}
