#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string path;
int n;
ll xi,yi,xf,yf;
ll res = 0;
bool f(ll x){
    ll valx = (x/n)*(count(path.begin(),path.end(),'R') - count(path.begin(),path.end(),'L'));
    ll valy = (x/n)*(count(path.begin(),path.end(),'U') - count(path.begin(),path.end(),'D'));
    for(int i = 0 ; i < x%n ; i++){
        if(path[i]=='R') valx++;
        if(path[i]=='L') valx--;
        if(path[i]=='U') valy++;
        if(path[i]=='D') valy--;
    }
    ll xm = xi + valx, ym = yi + valy;
    return (abs(xm-xf) + abs(ym-yf)) <= x;
}
int main(){
    cin >> xi >> yi >> xf >> yf;
    cin >> n;
    cin >> path;
    ll l = 0, r = 1e15, med;
    while( l < r ){
        med = l + (r-l)/2;
        if(f(med)) r = med;
        else l = med+1;
    }
    cout << (l==1e15 ? -1:l) << endl;
    return 0;
}