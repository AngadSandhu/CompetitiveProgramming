#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int deg[200005];
ll d[1000][1000];
int rf[200005];
int main() {
	cin >> n >>  m >> k;
	vector<pair<ll,pair<int,int>>> ed;
	for(int i = 0 ; i < m ; i ++){
		int x,y;ll w; cin >> x >> y >> w;
		ed.push_back({w,{--x,--y}});
	}
	sort(ed.begin(),ed.end());
	if(m>k) ed.resize(k);
	m = ed.size();
	for(int i = 0 ; i < m ;i++){
		pair<int,int> u = ed[i].second;
		deg[u.first]++;
		deg[u.second]++;
	}
	int cnt = 0;
	for(int i = 0 ; i < n ; i ++){
		if(deg[i]>0){
			rf[i] = cnt;
			cnt++;
		}
	}
	n = cnt;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			d[i][j] = ll(1e18);
		}
	}
	for(int i = 0 ; i < m ; i ++){
		pair<int,int> u = ed[i].second;
		d[rf[u.first]][rf[u.second]] = ed[i].first;
		d[rf[u.second]][rf[u.first]] = ed[i].first;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int l = 0 ; l < n ; l++){
				d[j][l] = min(d[j][l],d[j][i]+d[i][l]);
			}
		}
	}
	vector<long long>res;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			res.push_back(d[i][j]);
		}
	}
   sort(res.begin(),res.end());
   cout<<res[k-1] <<endl;
   return 0;
}
