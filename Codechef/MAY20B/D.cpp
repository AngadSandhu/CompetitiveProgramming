#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
ll x,y,l,r;
bool L[100], R[100];
ll res = -1, resid = LLONG_MAX;
ll f(ll z){ return (x&z)*(y&z); }
void mx(ll z){
    if(res <= f(z)){
        if(res==f(z)) resid = min(resid,z);
        else res = f(z), resid = z;
    }
}
ll get(int pos){ 
    ll a = x%(1ll<<pos), b = y%(1ll<<pos);
    return (a|b);
}
void menor(int pos, ll cur){
    if(R[pos]==0) return;
    mx(cur + get(pos));
}
void mayor(int pos,ll cur){
    for(int i = pos ; i >= 0 ; i--){
        cur += (1ll<<i)*L[i];
        if(L[i]==0) mx(cur + (1ll<<i) + get(i));
    }
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> x >> y >> l >> r;
        if(l > r) swap(l,r);
        for(int i = 0 ; i < 63 ; i++) L[i] = (l>>i)&1, R[i] = (r>>i)&1;
        ll cur = 0;
        int first = -1;
        for(int i = 62 ; i>= 0 ; i--){
            cur += (1ll<<i)*L[i];
            if(L[i] != R[i]){
                mayor(i-1,cur);
                first = i-1;
                cur += (1ll<<i);
                break;
            }
        }
        for(int i = first; i >= 0 ; i--){
            menor(i,cur);
            cur += (1ll<<i)*R[i];
        }
        mx(l), mx(r);
        if(resid > l) mx(resid-1);
        if(resid < r) mx(resid+1);
        cout << resid << endl;
        memset(R,0,sizeof R);
        memset(L,0,sizeof L);
        res = -1;
        resid = LLONG_MAX;
    }
	return 0;
}