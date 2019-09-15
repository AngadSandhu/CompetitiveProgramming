#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;

int main(){
	ll p,c;
	int cases = 0;
	while(cin >> p >> c,p > 0){
		cases++;
		p = min(p,c);
		vector<int> a(p);
		for(int i = 1 ; i <= p ; i++){
			a[i-1] = i;
		}
		vector<int>res;
		cout << "Case " << cases << ":" << endl;
		for(int i = 0 ;i < c ; i++){
			char m;
			cin >> m;
			//cout << endl;
			if(m=='N'){
				a.push_back(a[0]);
				//cout << a[0] << endl;
				res.push_back(a[0]);
				a.erase(a.begin());
			}else{
				int aux; cin >> aux;
				if(find(a.begin(),a.end(),aux)==a.end()){
					a.insert(a.begin(),aux);
				}else{
					a.erase(find(a.begin(),a.end(),aux));
					a.insert(a.begin(),aux);
				}
			}
			
		}
		for(auto v : res) cout << v << endl;
	}
	return 0;
}
