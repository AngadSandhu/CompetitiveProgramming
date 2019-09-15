#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, p = 0;
	while(cin >> n, n>=0){
		p++;
		vector<int>days(12);
		for(int &i:days) cin >> i;
		int ava = n, req;
		printf("Case %d:\n",p);
		for(int i = 0 ; i < 12 ; i++){
			cin >> req;
			if(req>ava) cout << "No problem. :(" << endl;
			else cout << "No problem! :D" << endl,ava-=req;
			ava += days[i];
		}
	}
	return 0;
}
