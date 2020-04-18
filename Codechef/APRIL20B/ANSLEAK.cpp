#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 505
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);

int n,m,k;
vector<vector<int>> c;
int maxscore = 0;
vector<int> defans;
vector<int> perm;
void score(vector<int> &v){
	int cur = 0, mini = INT_MAX;
	for(int i = 0; i < k ; i++){
		for(int j = 0 ; j < n ; j++){
			if(c[j][i] == v[j]) cur ++;
		}
		mini = min(mini,cur);
		cur = 0;
	}
	if(maxscore < mini){
		maxscore = mini;
		swap(defans,v);
	}
	return;
}
void shuff(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(perm.begin(), perm.end(), rng);
	return;
}
void solve(){
	shuff();
	vector<int> ans(n);
	unordered_set<int> st;
	int val;
	for(int i = 0 ; i < n ; i++){
		int maxi = 0, maxid = 0;
		vector<int> freq(10);
		for(int j = 0 ; j < k ; j++){
			if(st.find(j) != st.end()) continue;
			val = c[perm[i]][j];
			freq[val]++;
			if(maxi < freq[val]){
				maxi = freq[val];
				maxid = val;
			}
		}
		for(int j = 0 ; j < k ; j++){
			if(maxid == c[perm[i]][j]) st.insert(j);
		}
		ans[perm[i]] = maxid;
		if(st.size() == k) st.clear(); 
	}
	score(ans);
	return;
}
int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		cin >> n >> m >> k;
		c.resize(n);
		perm.resize(n);
		for(int i = 0 ; i < n ; i++){
			c[i].resize(k);
			for(int j = 0 ; j < k ; j++){
				cin >> c[i][j];
			}
			perm[i] = i;
		}
		for(int i = 0 ; i < 30 ; i++){
			solve();
		}
		for(int i = 0 ; i < n ; i++) cout << defans[i] << " "; cout << endl;
		maxscore = 0;
		defans.clear();
	}
	return 0;
}