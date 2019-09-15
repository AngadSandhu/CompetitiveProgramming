#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;

int main(){
	int t;cin >> t;
	while(t--){
		int l,m;
		cin >> l >> m;
		l *= 100;
		deque<int>lef,rig;
		int a;
		string s;
		for(int i = 0 ; i < m ; i++){
			cin >> a >> s;
			if(s=="left") lef.push_back(a);
			else rig.push_back(a);
		}
		//cout << lef.size() << " " << rig.size() << endl;
		int u = 0,v = 0;
		while(!lef.empty()){
			ll sum = 0;
			while(sum+lef.front()<=l && !lef.empty()){
				sum += lef.front();
				//cout << lef.front() <<" " <<  u<<  endl;
				lef.pop_front();
			}
			u++;
		}
		while(!rig.empty()){
			ll sum = 0;
			while(sum+rig.front()<=l && !rig.empty()){
				sum += rig.front();
				//cout << rig.front() <<" " << v <<  endl;
				rig.pop_front();
			}
			v++;
		}//cout << u<<" " << v << endl;
		cout << max(2*(u-1)+1,2*v) << endl;
	}
	return 0;
}
