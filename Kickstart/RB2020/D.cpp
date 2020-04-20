#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
double fac[N];
double get(int x,int y){
    return exp(fac[x+y-2] - fac[x-1] - fac[y-1] - (x+y-2)*log(2));
}
void init(){
    fac[0] = 0;
    for(int i = 1 ; i < N ; i++) fac[i] = fac[i-1] + log(i);
}
int main(){
	FIO;
	init();
    int t, caso = 0; cin >> t;
    while(t--){
        int w,h,l,u,r,d; cin >> w >> h >> l >> u >> r >> d;
        double res = 0, mul = 1.0;
        for(int f = u-1, c = r+1 ; f >= 1 && c <= w ; f--, c++){
            if(c == w) c = w-1, mul = 0.5;
            res += mul*get(f,c);
        }
        mul = 1.0;
        for(int f = d+1, c = l-1 ; f <= h && c >= 1 ; f++, c--){
            if(f == h) f = h-1, mul = 0.5;
            res += mul*get(f,c);
        }
        printf("Case #%d: %.6f\n",++caso,res);
    }
	return 0;
}