#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t, caso = 0; cin >> t;
    while(t--){
        int x,y; cin >> x >> y;
        bool sgx = x<0, sgy = y<0;
        x = abs(x);
        y = abs(y);
        bool posi = 1;
        string res = "";
        vector<pair<int,int>>sume(32,{-1,-1});
        bool last = 0;
        int b1 = 31 - __builtin_clz(x), b2 = 31 - __builtin_clz(y);
        if(x==0) b1 = 0;
        if(y==0) b2 = 0;
        for(int i = 0 ; i < 31 ; i++){
            if(((x>>i)&1 || (y>>i)&1) && last) posi = 0; 
            if(!((x>>i)&1) && !((y>>i)&1)) last = 1;
            if((x>>i)&1 && (y>>i)&1){
                if(i==0){
                    posi = 0;
                    continue;
                }
                if((x>>(i-1))&1 && (y>>(i-1))&1) posi = 0;
                if((x>>(i-1))&1) x += 1<<(i-1), sume[i-1] = {0,1};
                else if((y>>(i-1))&1) y += 1<<(i-1), sume[i-1] = {1,1};
            }
            if((x>>i)&1 && !((x>>(i+1))&1) && !((y>>(i+1))&1) && i<max(b1,b2)) x += 1<<i, sume[i] = {0,1};
            else if((y>>i)&1 && !((x>>(i+1))&1) && !((y>>(i+1))&1) && i < max(b1,b2)) y += 1<<i, sume[i] = {1,1};
            else if((x>>i)&1) sume[i] = {0,0};
            else if((y>>i)&1) sume[i] = {1,0};
        }
        for(int i = 0 ; i < 31 ; i++){
            int a = sume[i].first, b = sume[i].second;
            if(a==-1 || b==-1) continue;
            if(a==0 && b==1) res += (sgx?'E':'W');
            else if(a==0 && b==0) res += (sgx?'W':'E');
            else if(a==1 && b==0) res += (sgy?'S':'N');
            else if(a==1 && b==1) res += (sgy?'N':'S');
        }
        cout << "Case #" << ++caso << ": ";
        if(posi) cout << res << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
	return 0;
}