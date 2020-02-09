#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<int,int>,int> mp;
int main(){
    int t; cin >> t;
    while(t--){
        mp.clear();
        int n; cin >> n;
        string s; cin >> s;
        int x = 0, y = 0;
        mp[{0,0}] = 0;
        int res = INT_MAX;
        int r1= -1,r2 = -1;
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='L') x--;
            if(s[i]=='R') x++;
            if(s[i]=='D') y--;
            if(s[i]=='U') y++;
            if(mp.count({x,y}) > 0){
                if(res > i+1-mp[{x,y}]){
                    res = i + 1 - mp[{x,y}];
                    r1 = mp[{x,y}], r2 = i+1;
                }
            }
            mp[{x,y}] = i+1;
        }
        if(res==INT_MAX) cout << -1 << endl;
        else cout << r1+1 << " " << r2 << endl;

    }
    return 0;
}