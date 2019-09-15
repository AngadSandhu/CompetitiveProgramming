#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	while(cin >> n, n> 0){
		int a[n];
		bool b = 1;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
		}
		sort(a,a+n);
		for(int i = 1 ; i < n ; i++){
			if(a[i]-a[i-1] > 200) b = 0;
		}
		if(2*(1422-a[n-1]) > 200) b = 0;
		cout << (b?"POSSIBLE":"IMPOSSIBLE") << endl;
	}
	return 0;
}
