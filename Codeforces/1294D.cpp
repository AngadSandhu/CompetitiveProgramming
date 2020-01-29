#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int freq[400005];
int main(){
	int q,x; cin >> q >> x;
	int mx = 0;
	for(int i = 0 ; i < q ; i++){
		int y; cin >> y;
		freq[y%x]++;
		while(freq[mx%x]>0){
			freq[mx%x]--;
			mx++;
		}
		cout << mx << endl;		
	}
	return 0;
}
