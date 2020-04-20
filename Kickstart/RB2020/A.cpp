#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);


int main(){
	FIO;
	int t,caso = 0; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int &i : a) cin >> i;
        int cnt = 0;
        for(int i = 1 ; i < n-1 ; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]) cnt++;
        }
        cout << "Case #" << ++caso << ": " << cnt << endl;
    }
	return 0;
}