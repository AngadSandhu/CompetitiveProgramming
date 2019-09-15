#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105][105];
int n;
int main(){
	int t; scanf("%d",&t);
	int p = 0;
	while(t--){
		p++;
		char aux; cin >> aux >> aux >> n;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> a[i][j];
			}
		}
		bool b = 1;
		for(int i = 0 ; i < n &&b; i++){
			for(int j = 0 ; j < n &&b; j++){
				int ni = n-1-i, nj = n-1-j;
				if(!(a[i][j]==a[ni][nj] && a[i][j]>=0)) b = 0;
			}
		}
		printf("Test #%d: ",p);
		cout << (b?"Symmetric.":"Non-symmetric.") << endl;
	}
	return 0;
}
