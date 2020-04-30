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
        int n,k; cin >> n >> k;
        vector<int> a(n+1);
        for(int i = 1 ; i <= n ; i++) cin >> a[i]; a[0] = 0;
        int cur = 0, maxi = 0, maxid= 1;
        for(int l = 1, r = 2 ; r < n ; l++){
            while(r < n && r-l+1 < k){
                if((a[r] > a[r-1]) && (a[r] > a[r+1])) cur++;
                r++;
            }
            if(maxi < cur){
                maxi = cur;
                maxid = l;
            }
            if((a[l+1]>a[l]) && (a[l+1] > a[l+2])) cur--;
        }
        cout << maxi+1 << " " << maxid << endl;
    }
	return 0;
}