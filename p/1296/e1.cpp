#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[200005];
bool to[200005];
int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<char> v1,v2;
    v1.push_back(s[0]);
    bool res = 1;
    to[0] = 0;
    for(int i = 1 ; i < n && res; i++){
        if(v1.back() <= s[i]) v1.push_back(s[i]);
        else if(v2.empty() || v2.back() <= s[i]) v2.push_back(s[i]);
        else res = 0;
        if(s[i] == v1.back()) to[i] = 0;
        else to[i] = 1;
    }
    if(res==0) cout << "NO" << endl;
    else{
        cout <<"YES" << endl;
        for(int i = 0 ; i < n ; i++){
            cout << to[i];
        }
        cout << endl;
    }
    return 0;
}