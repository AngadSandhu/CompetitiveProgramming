#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
int BIT[2][400005];
int n,k;
void add(int x,int id){
	while(x < 2*k+2){
		BIT[id][x]++;
		x += (x&-x);
	}
}
int sum(int x,int id){
	int ret = 0;
	while(x > 0){
		ret += BIT[id][x];
		x -= (x&-x);
	}
	return ret;
}
int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		vector<int> a(n);
		for(int &i:a) cin >> i;
		for(int i = 0 ; i < n/2; i++){
			if(a[i] > a[n-i-1]) swap(a[i],a[n-i-1]);
		}
		vector<int> freq(2*k+2);
		for(int i = 0 ; i < n/2 ; i++){
			freq[a[i] + a[n-i-1]]++;
		}
		for(int i = 0 ; i < n/2 ; i++){
			add(a[i] + 1,0);
		}
		for(int i = n/2 ; i < n ; i++){
			add(a[i] + k,1);
		}
		int res = INT_MAX;
		for(int i = 0 ; i < 2*k+2 ; i++){
			int cur = n/2-freq[i];
			cur += n/2 - sum(i,0);
			cur += sum(i-1,1);
			res = min(res,cur);
		}
		cout << res << endl;
		for(int i = 0 ; i < 2*k+2 ; i++) BIT[0][i] = BIT[1][i] = 0;
	}
	return 0;
}