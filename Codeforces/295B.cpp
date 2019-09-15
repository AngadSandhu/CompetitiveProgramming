#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define N 1000005
using namespace std;
typedef long long ll;
int n;
int d[505][505];
bool valid[505];
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		valid[i] = 0;
		for(int j = 0 ; j < n ; j++){
			d[i][j] = INT_MAX;
			if(i==j) d[i][j] = 0;
			cin >> d[i][j];
		}
	}
	vector<int> added(n);
	vector<ll> res;
	for(int &i : added) cin >> i,i--;
	reverse(added.begin(),added.end());
	for(int k = 0 ; k < n ; k++){
		valid[added[k]] = 1;
		ll sum = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				d[i][j] = min(d[i][j],d[i][added[k]]+d[added[k]][j]);
				if(valid[i] && valid[j])sum += d[i][j];
				
			}
		}
		res.push_back(sum);
	}
	reverse(res.begin(),res.end());
	for(auto v :res)cout << v << " ";
	cout << endl;
	return 0;
}
