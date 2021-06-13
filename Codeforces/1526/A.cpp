#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(2*n);
		for(int &i : a) cin >> i;
		sort(a.begin(),a.end());
		deque<int> q;
		for(int i : a) q.push_back(i);
		while(!q.empty()){
			cout << q.front() << " ";
			q.pop_front();
			if(!q.empty()){
				cout << q.back() << " ";
				q.pop_back();
			}
		}
		cout << endl;
	}
	return 0;
}
