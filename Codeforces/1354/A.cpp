#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000005
int BIT[N];
int n,q;
void add(int x,int y){
    while(x < N){
        BIT[x] += y;
        x += (x&-x);
    }
}
int query(int x){
    int ret = 0;
    while(x > 0){
        ret += BIT[x];
        x -= (x&-x);
    }
    return ret;
}
int main(){
	FIO;
    cin >> n >> q;
    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        add(x,1);
    }
    for(int i = 0 ; i < q ; i++){
        int x; cin >> x;
        if(x > 0){
            add(x,1);
        }else{
            x = abs(x);
            int l = 1, r = n, med;
            while(l < r){
                med = l + (r-l)/2;
                if(query(med) < x) l = med+1;
                else r = med;
            }
            add(l,-1);
        }
    }
    bool flag = 0;
    for(int i = 1 ; i <= n && !flag; i++){
        if(query(i)-query(i-1) > 0){
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(!flag) cout << 0 << endl;
	return 0;
}