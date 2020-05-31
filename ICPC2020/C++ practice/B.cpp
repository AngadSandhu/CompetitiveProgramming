#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 55
int h[N];
int main(){
	FIO;
	int t, caso = 0; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++) cin >> h[i];
        int up = 0, low = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(h[i] < h[i+1]) up++;
            else if(h[i] > h[i+1]) low++;
        }
        cout << "Case " << ++caso << ": " << up << " " << low << endl;
    }
	return 0;
}