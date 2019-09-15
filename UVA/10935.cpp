#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;

int main(){
	int n;
	deque <int> q;
	while(cin >> n,n>0){
		q.clear();
		for(int i = 1 ; i <= n ;i++) q.push_back(i);
		vector<int> res;
		while(q.size()>1){
			res.push_back(q.front());
			q.pop_front();
			q.push_back(q.front());
			q.pop_front();
		}
		cout << "Discarded cards:";
		if(res.size()>=1) cout << " ";
		for(int i = 0 ; i < res.size() ;i++){
			cout << res[i];
			if(i!=res.size()-1) cout << ", ";
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
	}
	return 0;
}

