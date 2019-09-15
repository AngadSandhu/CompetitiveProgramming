#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int main() {
	int n;
	while(cin>>n,n>0){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ;j ++){
				cin >> a[i][j];
			}
		}
		int ir, ic, nr = 0,nc=0;
		for(int i = 0 ; i < n ; i++){
			int s = 0;
			for(int j = 0 ; j < n ;j ++){
				s+= a[i][j];
			}
			if(s%2) nr++, ir = i+1;
		}
		for(int j = 0 ; j < n ; j++){
			int s = 0;
			for(int i = 0 ; i < n ;i ++){
				s+= a[i][j];
			}
			if(s%2) nc++, ic = j+1;
		}
		if(nr==0&&nc==0) cout << "OK" << endl;
		else if(nr==1&&nc==1) printf("Change bit (%d,%d)\n",ir,ic);
		else cout << "Corrupt" << endl;
	}
	return 0;
}
