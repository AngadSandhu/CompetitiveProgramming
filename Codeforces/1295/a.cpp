#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2){
            cout << string(1,'7') + string((n-3)/2,'1') << endl;
        }else
        cout << string(n/2 ,'1') << endl;
    }
    return 0;
}