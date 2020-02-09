#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int n,q;
int ar[N];
int up[N],down[N];
int main() {
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++) cin >> ar[i];
    int cur = ar[0] < ar[1];
    for(int i = 0 ; i < n-1 ; i++){
        up[i] = cur;
        if(ar[i] > ar[i+1] && i!=n-2 && ar[i+1] < ar[i+2] ) cur++;
    }
    up[n-1] = cur;
    cur = ar[0] > ar[1];
    for(int i = 0 ; i < n-1 ; i++){
        down[i] = cur;
        if(ar[i] < ar[i+1] && i!=n-2 && ar[i+1] > ar[i+2]) cur++;
    }
    down[n-1] = cur;
    while(q--){
       int l,r; cin >> l >> r;
       l--; r--;
       int c1 = up[r] - up[l] , c2 = down[r] - down[l];
       if(ar[l] < ar[l+1]) c1++;
       if(r < n-1 && ar[r] < ar[r+1] && ar[r-1] > ar[r]) c1--;
       if(ar[l] > ar[l+1]) c2++;
       if(r < n-1 && ar[r] > ar[r+1] && ar[r-1] < ar[r]) c2--;

       cout << (c1==c2 ? "YES":"NO") << endl;
    }
	return 0;
}