#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
#define PI acos(-1)
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fixed << setprecision(12) << cos(PI/(4*n))/sin(PI/(2*n)) << endl;
    }
	return 0;
}