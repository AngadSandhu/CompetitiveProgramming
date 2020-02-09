#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[20];
int main() {
    p[0] = 1;
    for(int i = 1 ; i <= 18 ; i++) p[i] = 10*p[i-1];
    int t; cin >> t;
    while(t--){
        ll n,a,b,d,ans,s;
        cin >> n;
        cin >> a;
        cout << 2*p[n] + a << endl;
        cin >> b;
        cout << p[n]-b << endl;
        cin >> d;
        cout << p[n]-d << endl;
        cin >> ans;
        if(ans==-1) return 0;
    }
	return 0;
}
