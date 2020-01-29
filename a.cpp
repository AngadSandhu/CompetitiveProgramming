#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string a,b; cin >> a >> b;
		deque<int> qa,qb;
		int cur = 1;
		string na,nb;
		na = a;
		nb = b;
		na.resize(unique(na.begin(),na.end())-na.begin());
		nb.resize(unique(nb.begin(),nb.end())-nb.begin());
		for(int i = a.size()-2; i>=0 ; i--){
			if(a[i]==a[i+1]) cur++;
			else{
				qa.push_back(cur);
			}
		}
		cur = 1;
		for(int i = b.size()-2; i>=0 ; i--){
			if(b[i]==b[i+1]) cur++;
			else{
				qb.push_back(cur);
			}
		}
		bool res = 1;
		for(int i = 0 ; i < na.size() ; i++){
			if(na[i]!=nb[i]){
				res = 0;
				break;
			}else{
				if(qa.front()<=qb.front()){
					qa.pop_front();
					qb.pop_front();
				}else{
					res = 0;
					break;
				}
			}
		}
		cout << (res?"YES":"NO") << endl;
	}
	return 0;
}
