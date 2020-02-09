#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[200005];
vector<char> v[27];
int to[200005];
int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<char> v1,v2;
    for(int i = 0 ; i < n ; i++){
        int mini = 30,miniid;
        for(int j = 0; j < 27; j ++){
            if(!v[j].empty() && v[j].back() <= s[i]){
                if(mini > s[i]-v[j].back()){
                    mini = s[i]-v[j].back();
                    miniid = j;
                }
            }
        }
        if(mini==30){
            for(int j  = 0 ; j < 27 ; j++){
                if(v[j].empty()){
                    v[j].push_back(s[i]);
                    to[i] = j;
                    break;
                }
            }
        }else{
            v[miniid].push_back(s[i]);
            to[i] = miniid;
        }
    }
    int res = 0;
    for(int i = 0 ; i < 27 ; i++){
        if(!v[i].empty()) res++;
    }
    cout << res << endl;
    for(int i = 0 ; i < n ; i++){
        cout << to[i]+1 << " ";
    }
    cout << endl;
    return 0;
}