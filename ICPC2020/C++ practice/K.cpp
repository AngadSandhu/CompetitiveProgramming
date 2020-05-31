#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005
bool isfib[N];
int f[N];
int n;
int main(){
	FIO;
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    isfib[1] = 1;
    for(int i = 3 ; i <= 100 ; i++){
        f[i] = f[i-1] + f[i-2];
        if(f[i] > N) break;
        isfib[f[i]] = 1;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << (isfib[i] ? 'O' : 'o');
    }
    cout << endl;
	return 0;
}