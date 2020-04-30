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
        int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
        if(((a+b)*n >= (c-d))&&((a-b)*n <= (c+d))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}