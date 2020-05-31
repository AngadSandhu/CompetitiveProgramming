#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
ll n;
ll ar[100];
int main(){
	FIO;
    ar[1] = ar[2] = ar[3] = 1;
    int caso = 0;
	while(cin >> n , n > 0){
        for(int i = 4 ; i <= n ; i++) ar[i] = ar[i-1] + ar[i-2] + ar[i-3];
        cout << "Case " << ++caso << ": " << ar[n] << endl;
    }
	return 0;
}