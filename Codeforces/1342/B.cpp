#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        string s; cin >> s;
        set<char> st;
        for(int i = 0 ; i < s.size() ; i++) st.insert(s[i]);
        if(st.size()==1){
            cout << s << endl;
        }else{
            for(int i = 0 ; i < s.size()-1 ; i++){
                cout << s[i];
                if((s[i]=='0' && s[i+1]=='1') || (s[i]=='1' && s[i+1]=='0')) continue;
                else if(s[i]=='0') cout << '1';
                else cout << '0';
            }
            cout << s.back();
            cout << endl;
        }
    }
	return 0;
}