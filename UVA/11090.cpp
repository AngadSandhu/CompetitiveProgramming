#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,m;
vector<pair<ii,double>> ed;
double d[55];
bool bellman(double k){
	for(int i = 0 ; i < n ; i++) d[i] = 1.0*(1e10);
	for(int i = 0 ; i < m  ; i++) ed[i].second -= k;
	d[0] = 0;
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = 0 ; j < m ; j++){
			int u = ed[j].first.first, v = ed[j].first.second;
			double w = ed[j].second;
			if(d[v] > d[u] + w){
				d[v] = d[u]+w;
			}
		}
	}
	bool b = 1;
	for(int j = 0 ; j < m ; j++){
		int u = ed[j].first.first, v = ed[j].first.second;
		double w = ed[j].second;
		if(d[v] > d[u] + w) b = 0;
	}
	for(int i = 0 ; i < m ; i++) ed[i].second += k;
	return b;
}
double binary(){
	double l = 0, r = 10000000+5, med;
	while((r-l)>eps){
		med = (r-l)/2 + l;
		if(!bellman(med)) r = med;
		else l = med;
	}
	return l;
}
int main() {
	int t; cin >> t;
	int p = 0;
	while(t--){
		p++;
		cin >> n >> m;
		ed.clear();
		for(int i = 0 ; i < m ; i ++){
			int x,y;
			double w;
			cin >> x >> y >> w;
			ed.push_back({{--x,--y},w});
		}
		printf("Case #%d: ",p);
		if(bellman( 10000000)) cout << "No cycle found." << endl;
		else printf("%.2f",binary()), cout << endl;
	}
	return 0;
}
