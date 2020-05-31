#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 40005

int main(){
	FIO;
    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    int a=0,b=0;
    for(int i = 0 ; i < n ; i++) if(s[i]=='(') a++; else b++;
    if(a==b){
    stack<int> q1,q2;
    for(int i = 0 ; i < n ; i++){
        if(s[i]=='('){
            if(q2.empty()){
                q1.push(i);
            }else{
                if(q2.size()==1) res += i-q2.top()+1;
                q2.pop();
            }
        }else{
            if(q1.empty()){
                q2.push(i);
            }else{
                q1.pop();
            }
        }
    }
    cout << res << endl;
    }else{
        cout << -1 << endl;
    }
	return 0;
}