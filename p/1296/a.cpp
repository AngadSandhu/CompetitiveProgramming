#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int c = 0;
        for(int i = 0 ; i <n ; i++){
            int x; cin >> x;
            if(x%2) c++;
        }
        if(c%2 || (c>0 && (n-c) > 0)) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}