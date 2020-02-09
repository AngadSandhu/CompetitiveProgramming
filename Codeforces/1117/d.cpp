#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string path;
int n;
ll xi,yi,xf,yf;
ll res = 0;
int main(){
    cin >> xi >> yi >> xf >> yf;
    cin >> n;
    cin >> path;
    if(xi <= xf && yi <= yf){
        ll a = xf - xi, b = yf - yi;
        ll c = 2*count(path.begin(),path.end(),'R'), d = 2*count(path.begin(),path.end(),'U');
        if(a < b){
            ll need = (b-a+1)/2;
            if(need < d/2){
                cout << -1 << endl;
                return 0;
            }
            
        }
        if((c==0 && xf!=xi) || (d==0 && yf!=yi)){
            cout << -1 << endl;
            return 0;
        }
        res += n*max(a/c,b/d);
        xi += c*max(a/c,b/d);
        yi += d*max(a/c,b/d);
        if(a/c > b/d){
            for(int i = 0 ; i < n && xi < xf ;i++){
                if(path[i] == 'R') xi+=2,res++;
            }
        }else{
            for(int i = 0 ; i < n && yi < yf ;i++){
                if(path[i] == 'U') yi+=2,res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}