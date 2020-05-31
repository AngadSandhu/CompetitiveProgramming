#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10000

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        string s; cin >> s;
        vector<int> freq(26);
        for(int i = 0 ; i < n ; i++) freq[s[i]-'a']++;
        int used = 0, cur = k;
        string ans;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]==0) continue;
            if(freq[i] < cur) used = freq[i], cur -= freq[i], freq[i] = 0;
            else used = cur, freq[i] -= cur, cur = 0,  i--;
            if(cur==0){
                k = used;
                ans += char(i+1+'a');
                cur = k;
            }
        }
        cout << ans << endl;
    }
	return 0;
}