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
        int n,q; cin >> n >> q;
        string s; cin >> s;
        vector<int> freq(26), acum(27);
        for(int i = 0 ; i < n ; i++) freq[s[i]-'a']++;
        sort(freq.begin(),freq.end());
        acum[0] = 0;
        for(int i = 1 ; i <= 26 ; i++) acum[i] = acum[i-1] + freq[i-1];
        while(q--){
            int c; cin >> c;
            int pos = lower_bound(freq.begin(),freq.end(),c)-freq.begin();
            cout << n - acum[pos] - c*(26-pos) << endl;
        }
    }
	return 0;
}