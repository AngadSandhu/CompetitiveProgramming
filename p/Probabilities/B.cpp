#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	string s; cin >> s;
    long double p; cin >> p;
    int n = s.size(), c = count(s.begin(),s.end(),'?'),o = count(s.begin(),s.end(),'1');
    long double ans = 1.0 * (o + p*c)/n;
    cout << fixed << setprecision(5) << ans << endl;
	return 0;
}