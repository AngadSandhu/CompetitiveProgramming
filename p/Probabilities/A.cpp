#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
#define eps 1e-9
int main(){
	FIO;
	int a,b,c,d; cin >> a >> b >> c >> d;
    double p1 = 1.0*a/b, p2 = 1.0*c/d;
    double x = 1.0*(1-p1)*(1-p2);
    double ans = 0, cur = 1;
    while(p1*cur > eps){
        ans += p1*cur;
        cur *= x;
    }
    cout << fixed << setprecision(7) << ans << endl;
	return 0;
}