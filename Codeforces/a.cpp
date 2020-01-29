#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,sx,sy;
pair<int,int> p[200005];
pair<int, pair<int,int> > a[4];
int main(){
	cin >> n >> sx >> sy;
	a[0] = {0,{-1,0}};
	a[1] = {0,{1,0}};
	a[2] = {0,{0,-1}};
	a[3] = {0,{0,1}};
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second;
		if(p[i].first<sx) a[0].first++;
		if(p[i].first>sx) a[1].first++;
		if(p[i].second<sy) a[2].first++;
		if(p[i].second>sy) a[3].first++;
	}
	sort(a,a+4);
	for(int i = 3; i >= 0 ; i--){
		int nx = sx + a[i].second.first, ny = sy + a[i].second.second;
		if(nx>=0 && nx<=1e9 && ny>=0 && ny<=1e9){
			cout << a[i].first << endl;
			cout << nx << " " << ny << endl;
			return 0;
		}
	}
	return 0;
}

