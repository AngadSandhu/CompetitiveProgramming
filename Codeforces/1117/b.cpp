#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hap[200005];

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++) cin >> hap[i];
    sort(hap,hap+n);
    cout << (m/(k+1)) * (k*hap[n-1] + hap[n-2]) + m%(k+1) * hap[n-1] << endl;

    return 0;
}