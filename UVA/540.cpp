#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
map<int,int> gp;
deque<int> q[1000005];
int freq[1005];
int main(){
	int n;
	int p =0;
	while(cin >> n,n > 0){
		p++;
		for(int i = 0 ; i < n ; i++) q[i].clear(),freq[i] = 0;
		gp.clear();
		for(int i = 0 ; i < n ; i++){
			int a; cin >> a;
			for(int j = 0 ; j < a ; j++){
				int aux; cin >> aux;
				gp[aux] = i;
			}
		}
		deque<int>qq;
		string s;
		cout << "Scenario #" << p << endl;
		while(cin >> s){
			if(s=="STOP") break;
			if(s=="ENQUEUE"){
				int aux; cin >> aux;
				if(q[gp[aux]].empty()) qq.push_back(gp[aux]);
				q[gp[aux]].push_back(aux);
				freq[gp[aux]]++;
			}else{
				cout << q[qq.front()].front() << endl;
				freq[qq.front()]--;
				q[qq.front()].pop_front();
				if(freq[qq.front()]==0) qq.pop_front();
			}
		}
		cout << endl;
	}
	return 0;
}
