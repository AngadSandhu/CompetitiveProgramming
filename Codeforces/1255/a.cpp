#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        int cur = abs(b-a);
        int res = cur/5;
        cur%=5;
        res += cur/2;
        cur %=2;
        res += cur;
        cout << res << endl;
    }
    return 0;
}