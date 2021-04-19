#include<bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define maxn 300005
typedef long long ll;
ll n,a[maxn];
map<ll,ll>mp;
priority_queue<ll,vector<ll>,greater<ll> >q;
ll ans,t[maxn];
ll lowbit(ll x) {
    return x&(-x);
}
void add(ll x,ll num) {
 
    while(x<=n) t[x]+=num,x+=lowbit(x);
}
ll qq(ll x) {
    //if(x==0) return 0;
    ll ans=0;
    while(x>0) {
        ans+=t[x];
        x-=lowbit(x);
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 1 ; i <= n ;i++) cin >> a[i],q.push(a[i]),mp[a[i]] = i,add(i,i),add(i+1,-i);
    int l =1 ,r = n; //如果移动到左右两侧，对应的位置在哪
    while(q.size()) {
        int x = q.top();
        q.pop();
        x = mp[x];
        int pos = qq(x)  ; //真实位置
        int L = pos - l;
        int R = r-pos;
        //  cout<<pos<<endl;
        if(L<=R) {
            //移动到左边
            //移动到l
            ans+=L;
            add(1,1);
            add(x,-1);
            l++;
 
        } else {
            //移动到右边
            //移动到r
            ans+=R;
            add(x+1,-1);
            r--;
        }
 
    }
    cout << ans << endl;
    return  0;
}