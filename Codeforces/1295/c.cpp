#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int go[100005][30],last[30];
int dp[100005][30];
int main(){
    int t; cin >> t;
    while(t--){
        string s,t;
        cin >> s >> t;
        s = 'a' + s;
        for(int j = 0 ; j < 27; j ++){
                last[j]= -1;
        }
        for(int i = 0 ; i <= s.size() ; i++){
            for(int j = 0 ; j < 27; j ++){
                go[i][j] = -1;
                dp[i][j] = -1;
            }
        }
        for(int i = s.size() ; i>=0 ; i--){
            for(int j = 0 ; j < 27 ; j++){
                go[i][j] = last[j];
            }
            last[s[i]-'a'] = i;
        }
        int j = 0,i = 0,res= 0;
        bool pos = 1;
        while(j < t.size() && pos){
            i = 0;
            if(go[i][t[j]-'a'] == -1) pos = 0;
            while(i <= s.size() && j < t.size() && pos){
                if(go[i][t[j]-'a'] == -1) break;
                i = go[i][t[j]-'a'];
                j++;
            }
            res++;
        }
        cout << (pos==0?-1:res) << endl;
    }
    return 0;
}