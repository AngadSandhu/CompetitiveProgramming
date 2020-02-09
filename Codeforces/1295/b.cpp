#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n,x;
        string s;
        cin >> n >> x >> s;
        vector<int> dif(n);
        bool pos = 0;
        dif[0] = (s[0]=='1' ? -1:1);
        for(int i = 1 ; i < n ;i ++){
            if(s[i]=='1') dif[i] = dif[i-1] - 1;
            else dif[i] = dif[i-1] + 1;
            if(dif[i] == x) pos = 1;
        }
        int findif = dif[n-1];
        if(findif==0){
            if(pos==1) cout << -1 << endl;
            else cout << 0 << endl;
            continue;
        }
        int res = 0;
        for(int i = 0 ; i < n ;i ++){
            if( (x-dif[i]) % (findif) == 0 && (x-dif[i])/(findif) >= 0) res++;
        }
        if(x==0) res++;
        cout << res << endl;
    }
    return 0;
}