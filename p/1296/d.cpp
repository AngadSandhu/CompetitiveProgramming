#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[200005];
int main(){
        ll n,a,b,k; cin >> n >> a >> b >> k;
        for(int i = 0 ;i < n ;i++) cin >> ar[i];
        for(int i = 0 ; i < n ; i++){
            if(ar[i] <= a) ar[i] = 0;
            else ar[i] -= a;
            ar[i] = ar[i] % (a+b);
            if(ar[i] <= b && ar[i] > 0) ar[i] = (ar[i]+ a - 1)/a;
            else ar[i] = 0;
        }
        sort(ar,ar+n);
        ll res = 0,resid = 0;
        for(int i = 0 ; i < n ; i++){
            if(res + ar[i] <= k) res+= ar[i],resid =i+1;
        }
        cout << resid << endl;
    return 0;
}