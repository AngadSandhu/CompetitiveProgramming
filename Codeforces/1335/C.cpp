#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100
char ar[N][N];
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), freq(n+1);
        for(int &i:a) cin >> i;
        set<int> st;
        int maxi = INT_MIN, maxid = 0;
        for(int i = 0 ; i < n ; i++){
            st.insert(a[i]);
            freq[a[i]]++;
            if(maxi < freq[a[i]]){
                maxi = freq[a[i]];
                maxid = a[i];
            }
        }
        int ans = INT_MIN;
        ans = max(min(maxi-1,(int)st.size()),min(maxi,(int)st.size()-1));
        cout << ans << endl;
    }
	return 0;
}