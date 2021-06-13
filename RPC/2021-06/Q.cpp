#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    
    for(int i = 0; i < n/3; i++){
        if(s[i] == s[i+n/3] || s[i] == s[i+n/3*2]) cout << s[i];
        else cout << s[i+n/3];
    }
    cout << endl;
    return 0;
}