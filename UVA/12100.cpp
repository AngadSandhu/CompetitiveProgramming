#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
int freq[10];
int pri[105];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		memset(freq,0,sizeof freq);
		cin >> n >> m;
		deque<int>q;
		for(int i = 0 ; i < n ;i++){
			q.push_back(i);
		}
		for(int i = 0 ; i < n ;i++){
			int a;cin >> a;
			pri[i] = a;
			freq[a]++;
		}
		bool found = 0; int c = 0;
		while(!q.empty() && !found){
			int aux = 9;
			while(freq[aux]==0) aux--;
			
			if(pri[q.front()]==aux){
				if(q.front()==m) found = 1;
				c++;
				q.pop_front();
				freq[aux]--;
			}else{
				q.push_back(q.front());
				q.pop_front();
			}
		}
		cout << c << endl;
	}
	return 0;
}
