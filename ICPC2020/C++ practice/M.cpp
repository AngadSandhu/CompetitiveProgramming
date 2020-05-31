#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int pref[N], p[N];
ll freq[26];
string s;
int n,m;
int main(){
	FIO;
	int t; cin >> t;
	while(t--){
	cin >> n >>m >> s;
	for(int i = 0 ; i < n ; i++) freq[s[i]-'a']++;
	for(int i = 0 ; i < m ; i++) cin >> p[i], pref[p[i]-1]++;
	ll sum = 0;
	for(int i = n-1 ; i >= 0 ; i--){
		sum += pref[i];
		freq[s[i]-'a'] += sum;
	}
	for(int i = 0 ; i < 26 ; i++) cout << freq[i] << " ";
	cout << endl;
	for(int i = 0 ; i < 26 ; i++) freq[i] = 0;
	for(int i = 0 ; i < n ; i++) pref[i] = 0;
	}
	return 0;
}