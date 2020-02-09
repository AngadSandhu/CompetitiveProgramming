#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int a,b,c,s; cin >> s >> a >> b >> c;
        if(a+b+c <= s){
            cout << 1 << endl;
            continue;
        }
        if(a<c){
            if(a+b <= s) cout << 2 <<endl;
            else cout << 3 << endl;
        }else{
            if(b+c <= s) cout << 2 << endl;
            else cout << 3 << endl;
        }
    }
	return 0;
}