#include<bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define N 300005
const long long INF = (1ll<<60);
int a[N],b[N],c[N];
long long izq[N],der[N];
int tree[N];
void update(int pos, int val){
    for(int i = pos; i < N; i+=i&-i)
        tree[i] += val;
}
int mayores(int pos){
    int res = 0;
    for(int i = N-1; i > 0; i-=i&-i)
        res += tree[i];
    for(int i = pos; i > 0; i-=i&-i)
        res -= tree[i];
    return res;
}
map<int,int> mp;
int main(){FIN;
    int n;
    cin >> n;
    long long res = INF;
    for(int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b+1,b+1+n);
    for(int i = 1; i <= n; i++){
        if(mp.count(b[i]) == 0) mp[b[i]] = mp.size()+1;
    }
    for(int i = 1; i <= n; i++){
       a[i] = mp[a[i]];
    }
    for(int i = 1; i <= n; i++)
        izq[i] = izq[i-1] + mayores(a[i]), update(a[i],1);
    
    memset(tree,0,sizeof tree);
    
    for(int i = n; i > 0; i--)
        der[i] = der[i+1] + mayores(a[i]), update(a[i],1);
    for(int i = 0; i <= n; i++)
        res = min(res,izq[i]+der[i+1]);
    cout << res << endl;
    return 0;
}